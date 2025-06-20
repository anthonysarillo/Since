// GAME
#include "Critter.h"
#include "CritterConfig.h"
#include "CombatInterface.h"
#include "InteractionInterface.h"
#include "SinceHUD.h"
#include "CritterController.h"

// ENGINE
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SpotLightComponent.h"


ACritter::ACritter()
{
 	PrimaryActorTick.bCanEverTick = true;

	// INPUT
	Sneaking = false;
	Jumping = false;
	ThirdPersonView = true;
	ChestLightOn = false;
	Interacting = false;
	bReady = false;
	Aiming = false;
	Attacking = false;
	MeleeOneHand = false;
	MeleeTwoHand = false;
	Pistol = false;
	Rifle = false;
	Shotgun = false;

	// INTERACTION
	InteractionCheckFrequency = 0.1f;
	InteractionCheckDistance = 250.0f;
	InteractionCheckDistanceFP = 200.0f;
	
	// COMBAT
	CombatCheckFrequency = 0.1f;
	CombatCheckDistance = 1000.0f;
	CombatCheckDistanceFP = 950.0f;

	// SPRING ARM
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	// THIRD PERSON CAMERA
	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm);
	ThirdPersonCamera->bAutoActivate = true;

	// THIRD PERSON CAMERA REF
	ThirdPersonCameraRef = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCameraRef"));
	ThirdPersonCameraRef->SetupAttachment(ThirdPersonCamera);
	ThirdPersonCameraRef->bAutoActivate = false;
	
	// FIRST PERSON CAMERA
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), "Head");
	FirstPersonCamera->bAutoActivate = false;

	// CHEST LIGHT COMPONENT
	ChestLightComp = CreateDefaultSubobject<USpotLightComponent>(TEXT("ChestLight"));
	ChestLightComp->SetupAttachment(GetMesh(), "chestlight");
	ChestLightComp->SetVisibility(false);

}

void ACritter::BeginPlay()
{
	Super::BeginPlay();

	CritterController= Cast<ACritterController>(GetController());
	HUD = Cast<ASinceHUD>(CritterController->GetHUD());
	
}

void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Must be configured in the Blueprint
	check(CritterConfig);

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(CritterConfig->CritterContext, 0);

	UEnhancedInputComponent* InputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	InputComp->BindAction(CritterConfig->Input_Move, ETriggerEvent::Triggered, this, &ACritter::Move);
	InputComp->BindAction(CritterConfig->Input_Look, ETriggerEvent::Triggered, this, &ACritter::Look);
	InputComp->BindAction(CritterConfig->Input_Sneak, ETriggerEvent::Triggered, this, &ACritter::Sneak);
	InputComp->BindAction(CritterConfig->Input_Jump, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	InputComp->BindAction(CritterConfig->Input_ChangeView, ETriggerEvent::Triggered, this, &ACritter::ChangeView);
	InputComp->BindAction(CritterConfig->Input_ChestLight, ETriggerEvent::Triggered, this, &ACritter::ChestLight);
	InputComp->BindAction(CritterConfig->Input_Activate, ETriggerEvent::Triggered, this, &ACritter::Activate);
	InputComp->BindAction(CritterConfig->Input_Ready, ETriggerEvent::Triggered, this, &ACritter::Ready);
	InputComp->BindAction(CritterConfig->Input_Aim, ETriggerEvent::Started, this, &ACritter::Aim);
	InputComp->BindAction(CritterConfig->Input_StopAim, ETriggerEvent::Completed, this, &ACritter::StopAim);
	InputComp->BindAction(CritterConfig->Input_Attack, ETriggerEvent::Started, this, &ACritter::Attack);
	InputComp->BindAction(CritterConfig->Input_Attack, ETriggerEvent::Completed, this, &ACritter::StopAttack);

}

void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld()->TimeSince(InteractionData.LastInteractionCheckTime) > InteractionCheckFrequency)
	{
		PerformInteractionCheck();
	}
	if (GetWorld()->TimeSince(CombatData.LastCombatCheckTime ) > CombatCheckFrequency)
	{
		PerformCombatCheck();
	}
}

void ACritter::PerformInteractionCheck()
{
	InteractionData.LastInteractionCheckTime = GetWorld()->GetTimeSeconds();

	FHitResult Hit;
	FHitResult HitFP;
	FVector Start;
	FVector StartFP;
	Start = GetPawnViewLocation();
	StartFP = FirstPersonCamera->GetComponentLocation();
	FVector End{Start + (GetViewRotation().Vector() * InteractionCheckDistance)};
	FVector EndFP{Start + (FirstPersonCamera->GetComponentRotation().Vector() * InteractionCheckDistanceFP)};
	FCollisionQueryParams QueryParams;
	FCollisionQueryParams QueryParamsFP;
	QueryParams.AddIgnoredActor(this);
	QueryParamsFP.AddIgnoredActor(this);

	float LookDirection = FVector::DotProduct(GetActorForwardVector(), GetViewRotation().Vector());
	
	if (ThirdPersonView == true && LookDirection > .5)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::White, false, .1, 0, .5);
	}
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility))
	{
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
		{
			if (Hit.GetActor() != InteractionData.CurrentInteractable && ThirdPersonView == true && LookDirection > .5)
			{
				FoundInteractable(Hit.GetActor());

					DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.5, 0, 1.5);

					return;
			}
			if (Hit.GetActor() == InteractionData.CurrentInteractable)
			{
				return;;
			}
		}
	}
	NoInteractableFound();

	if (ThirdPersonView == false)
	{
		DrawDebugLine(GetWorld(), StartFP, EndFP, FColor::White, false, .1, 0, .5);
	}
	if (GetWorld()->LineTraceSingleByChannel(HitFP, StartFP, EndFP, ECC_Visibility))
	{
		if (HitFP.GetActor()->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
		{
			if (HitFP.GetActor() != InteractionData.CurrentInteractable && ThirdPersonView == false) 
			{
				FoundInteractable(HitFP.GetActor());

				DrawDebugLine(GetWorld(), StartFP, EndFP, FColor::Green, false, 1.5, 0, 1.5);

				return;
			}
			if (HitFP.GetActor() == InteractionData.CurrentInteractable)
			{
				return;;
			}
		}
	}
	NoInteractableFound();
}

void ACritter::FoundInteractable(AActor* NewInteractable)
{
	if (IsInteracting())
	{
		EndInteract();
	}

	if (InteractionData.CurrentInteractable)
	{
		TargetInteractable = InteractionData.CurrentInteractable;
		TargetInteractable->EndFocus();
	}

	InteractionData.CurrentInteractable = NewInteractable;
	TargetInteractable = NewInteractable;

	HUD->UpdateInteractionWidget(&TargetInteractable->InteractableData);
	HUD->ShowBrackets();

	TargetInteractable->BeginFocus();
}

void ACritter::NoInteractableFound()
{
	if (IsInteracting())
	{
		GetWorldTimerManager().ClearTimer(TimerHandle_Interaction);
	}
	if (InteractionData.CurrentInteractable)
	{
		if (IsValid(TargetInteractable.GetObject()))
		{
			TargetInteractable->EndFocus();
			EndInteract();
		}
		HUD->HideInteractionWidget();
		HUD->HideBrackets();

		InteractionData.CurrentInteractable = nullptr;
		TargetInteractable = nullptr;
	}
}

void ACritter::BeginInteract()
{
	// verify nothing has changed with the interactable state since beginning interaction
	PerformInteractionCheck();

	if (InteractionData.CurrentInteractable)
	{
		if (IsValid(TargetInteractable.GetObject()))
		{
			TargetInteractable->BeginInteract();

			if (FMath::IsNearlyZero(TargetInteractable->InteractableData.InteractionDuration, 0.1f))
			{
				Activate();
			}
			else
			{
				GetWorldTimerManager().SetTimer(TimerHandle_Interaction,
												this,
												&ACritter::Activate,
												TargetInteractable->InteractableData.InteractionDuration,
												false);
			}
		}
	}
}

void ACritter::EndInteract()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_Interaction);

	if (IsValid(TargetInteractable.GetObject()))
	{
		TargetInteractable->EndInteract();
	}
}

void ACritter::Activate()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_Interaction);

	if (IsValid(TargetInteractable.GetObject()))
	{
		TargetInteractable->Interact(this);
	}
	
}

void ACritter::UpdateInteractionWidget() const
{
	if (IsValid(TargetInteractable.GetObject()))
	{
		HUD->UpdateInteractionWidget(&TargetInteractable->InteractableData);
	}
}

void ACritter::PerformCombatCheck()
{
	FHitResult Hit;
	FHitResult HitFP;
	FVector Start;
	FVector StartFP;
	Start = GetPawnViewLocation();
	StartFP = FirstPersonCamera->GetComponentLocation();
	FVector End{Start + (GetViewRotation().Vector() * CombatCheckDistance)};
	FVector EndFP{Start + (FirstPersonCamera->GetComponentRotation().Vector() * CombatCheckDistanceFP)};
	FCollisionQueryParams QueryParams;
	FCollisionQueryParams QueryParamsFP;
	QueryParams.AddIgnoredActor(this);
	QueryParamsFP.AddIgnoredActor(this);

	float LookDirection = FVector::DotProduct(GetActorForwardVector(), GetViewRotation().Vector());

	if (ThirdPersonView == true && LookDirection > .75)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::White, false, .1, 0, .5);
	}
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn))
	{
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UCombatInterface::StaticClass()))
		{
			if (Hit.GetActor() != CombatData.CurrentCombatant && ThirdPersonView == true && LookDirection > .75)
			{
				FoundCombatant(Hit.GetActor());

				DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.5, 0, 1.5);

				return;
			}
			if (Hit.GetActor() == CombatData.CurrentCombatant)
			{
				return;;
			}
		}
	}
	NoCombatantFound();

	if (ThirdPersonView == false)
	{
		DrawDebugLine(GetWorld(), StartFP, EndFP, FColor::White, false, .1, 0, .5);
	}
	if (GetWorld()->LineTraceSingleByChannel(HitFP, StartFP, EndFP, ECC_Pawn))
	{
		if (HitFP.GetActor()->GetClass()->ImplementsInterface(UCombatInterface::StaticClass()))
		{
			if (HitFP.GetActor() != CombatData.CurrentCombatant && ThirdPersonView == false)
			{
				FoundCombatant(HitFP.GetActor());

				DrawDebugLine(GetWorld(), StartFP, EndFP, FColor::Red, false, 1.5, 0, 1.5);

				return;
			}
			if (HitFP.GetActor() == CombatData.CurrentCombatant)
			{
				return;;
			}
		}
	}
	NoCombatantFound();
}

void ACritter::FoundCombatant(AActor* NewCombatant)
{
	if (IsInCombat())
	{
		EndCombat();
	}

	if (CombatData.CurrentCombatant)
	{
		TargetCombatant = CombatData.CurrentCombatant;
		TargetCombatant->EndTargeting();
	}

	CombatData.CurrentCombatant = NewCombatant;
	TargetCombatant = NewCombatant;

	HUD->UpdateCombatWidget(&TargetCombatant->CombatantData);
	HUD->ShowBrackets();

	TargetCombatant->BeginTargeting();
}

void ACritter::NoCombatantFound()
{
	if (IsInCombat())
	{
		GetWorldTimerManager().ClearTimer(TimerHandle_Combat);
	}
	if (CombatData.CurrentCombatant)
	{
		if (IsValid(TargetCombatant.GetObject()))
		{
			TargetCombatant->EndTargeting();
			EndCombat();
		}
		HUD->HideCombatWidget();
		HUD->HideBrackets();

		CombatData.CurrentCombatant = nullptr;
		TargetCombatant = nullptr;
	}
}

void ACritter::BeginCombat()
{
	// verify nothing has changed with the Combat state since beginning Combat
	PerformCombatCheck();

	if (CombatData.CurrentCombatant)
	{
		if (IsValid(TargetCombatant.GetObject()))
		{
			TargetCombatant->BeginTargeting();

			if (FMath::IsNearlyZero(TargetCombatant->CombatantData.CombatDuration, 0.1f))
			{
				Attack();
			}
			else
			{
				GetWorldTimerManager().SetTimer(TimerHandle_Combat,
												this,
												&ACritter::Attack,
												TargetCombatant->CombatantData.CombatDuration,
												false);
			}
		}
	}
}

void ACritter::EndCombat()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_Combat);

	if (IsValid(TargetCombatant.GetObject()))
	{
		TargetCombatant->EndCombat();
	}
}

void ACritter::Attack()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_Combat);

	if (IsValid(TargetCombatant.GetObject()))
	{
		TargetCombatant->Combat(this);
	}

	Attacking = true;
}

void ACritter::StopAttack()
{
	Attacking = false;
}

void ACritter::UpdateCombatWidget() const
{
	if (IsValid(TargetCombatant.GetObject()))
	{
		HUD->UpdateCombatWidget(&TargetCombatant->CombatantData);
	}
}

void ACritter::Move(const FInputActionInstance& Instance)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	const FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();

	AddMovementInput(ControlRot.Vector(), AxisValue.Y);

	const FVector RightVector = ControlRot.RotateVector(FVector::RightVector);
	AddMovementInput(RightVector, AxisValue.X);
}

void ACritter::Look(const FInputActionValue& InputValue)
{
	const FVector2D Value = InputValue.Get<FVector2D>();
	
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void ACritter::Sneak()
{
	
}

void ACritter::ChangeView()
{
	
}

void ACritter::ChestLight()
{
	
}

void ACritter::Ready()
{
	
}

void ACritter::Aim()
{
	Aiming = true;
}

void ACritter::StopAim()
{
	Aiming = false;
}

FVector ACritter::GetPawnViewLocation() const
{
	return ThirdPersonCamera->GetComponentLocation();
}

FVector ACritter::GetFirstPersonPawnViewLocation() const
{
	return FirstPersonCamera->GetComponentLocation();
}












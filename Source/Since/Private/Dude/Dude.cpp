// GAME
#include "Dude/Dude.h"
#include "Dude/DudeInputConfig.h"
#include "GAS/SinceGameplayAbility.h"
#include "GAS/WeaponSet.h"
#include "GAS/Qualities.h"
#include "GAS/Bonuses.h"
#include "GAS/Talents.h"
#include "GAS/DerivedSet.h"
#include "GAS/PrimarySet.h"
#include "GAS/SinceAbilitySystemComponent.h"

// ENGINE
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"



ADude::ADude()
{
	PrimaryActorTick.bCanEverTick = true;

	// SinceAbilitySystemComponent
	SinceAbilitySystemComponent = CreateDefaultSubobject<USinceAbilitySystemComponent>(TEXT("SinceAbilitySystemComponent"));
	SinceAbilitySystemComponent->SetIsReplicated(true);
	SinceAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	// AttributeSets
	PrimarySet = CreateDefaultSubobject<UPrimarySet>(TEXT("PrimarySet"));
	DerivedSet = CreateDefaultSubobject<UDerivedSet>(TEXT("DerivedSet"));
	Talents = CreateDefaultSubobject<UTalents>(TEXT("Talents"));
	Bonuses = CreateDefaultSubobject<UBonuses>(TEXT("Bonuses"));
	Qualities = CreateDefaultSubobject<UQualities>(TEXT("Qualities"));
	WeaponSet = CreateDefaultSubobject<UWeaponSet>(TEXT("WeaponSet"));

	// SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	// ThirdPersonCamera
	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm);
	ThirdPersonCamera->FieldOfView = 75;

}

void ADude::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (IsValid(SinceAbilitySystemComponent))
	{
		PrimarySet = SinceAbilitySystemComponent->GetSet<UPrimarySet>();
		DerivedSet = SinceAbilitySystemComponent->GetSet<UDerivedSet>();
		WeaponSet = SinceAbilitySystemComponent->GetSet<UWeaponSet>();
	}
}

void ADude::GiveAbilities()
{
	if (HasAuthority() && SinceAbilitySystemComponent)
	{
		for (TSubclassOf<USinceGameplayAbility>& StartupAbility : DudeAbilities)
		{
			SinceAbilitySystemComponent->GiveAbility(
				FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this));
		}
	}
}

void ADude::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Must be Configured in Blueprint
	check(DudeInputConfig)

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(DudeInputConfig->DudeContext, 0);

	UEnhancedInputComponent* InputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	InputComp->BindAction(DudeInputConfig->Input_Move, ETriggerEvent::Triggered, this, &ADude::Move);
	InputComp->BindAction(DudeInputConfig->Input_Look, ETriggerEvent::Triggered, this, &ADude::Look);



	if (SinceAbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("confirm", "Cancel", "ESinceAbilityInputID",
			static_cast<int32>(ESinceAbilityInputID::Confirm), static_cast<int32>(ESinceAbilityInputID::Cancel));
		SinceAbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

void ADude::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	SinceAbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveAbilities();
}

void ADude::BeginPlay()
{
	Super::BeginPlay();


	
}

void ADude::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADude::Move(const FInputActionInstance& Instance)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	const FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();

	AddMovementInput(ControlRot.Vector(), AxisValue.Y);

	const FVector RightVector = ControlRot.RotateVector(FVector::RightVector);
	AddMovementInput(RightVector, AxisValue.X);
}

void ADude::Look(const FInputActionValue& InputValue)
{
	const FVector2D Value = InputValue.Get<FVector2D>();
	
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

UAbilitySystemComponent* ADude::GetAbilitySystemComponent() const
{
	return SinceAbilitySystemComponent;
}

const UPrimarySet* ADude::GetPrimarySet() 
{
	return PrimarySet;
}

const UDerivedSet* ADude::GetDerivedSet() 
{
	return DerivedSet;
}

const UTalents* ADude::GetTalents()
{
	return Talents;
}

const UBonuses* ADude::GetBonuses()
{
	return Bonuses;
}

const UQualities* ADude::GetQualities()
{
	return Qualities;
}

const UWeaponSet* ADude::GetWeaponSet()
{
	return WeaponSet;
}

FVector ADude::GetPawnViewLocation() const
{
	return ThirdPersonCamera->GetComponentLocation();
}





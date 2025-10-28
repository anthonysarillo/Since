// Since - 2025


#include "Since/Public/Core/SincePlayerController.h"
#include "Inventory/InventoryComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Core/ContactComponent.h"
#include "Interaction/Highlightable.h"
#include "Item/ItemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Since/Since.h"
#include "UI/HeadsUpDisplay.h"

ASincePlayerController::ASincePlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	ContactTraceLength = 500.f;
	
}

void ASincePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ContactTrace();
}

void ASincePlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem))
	{
		Subsystem->AddMappingContext(SinceContext, 0);
	}

	InventoryComponent = FindComponentByClass<UInventoryComponent>();
	CreateHeadsUpDisplay();
}

void ASincePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(Input_Look, ETriggerEvent::Triggered, this, &ThisClass::Look);
	EnhancedInputComponent->BindAction(Input_Activate, ETriggerEvent::Started, this, &ThisClass::Activate);
	EnhancedInputComponent->BindAction(Input_Inventory, ETriggerEvent::Started, this, &ThisClass::ToggleInventory);
}

void ASincePlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn())) return;
	
	const FVector2D MovementVector = Value.Get<FVector2D>();

	// Find which way is forward
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
}

void ASincePlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void ASincePlayerController::Activate()
{
	UE_LOG(LogSince, Warning, TEXT("ASincePlayerController::Activate"))

	if (!ThisContact.IsValid()) return;

	UItemComponent* ItemComponent = ThisContact->FindComponentByClass<UItemComponent>();
	if (!IsValid(ItemComponent) || !InventoryComponent.IsValid()) return;
	
	InventoryComponent->TryAddItem(ItemComponent);
}

void ASincePlayerController::ToggleInventory()
{
	UE_LOG(LogSince, Warning, TEXT("ASincePlayerController::ToggleInventory"))

	if (!InventoryComponent.IsValid()) return;
	InventoryComponent->ToggleInventoryMenu();
}

void ASincePlayerController::CreateHeadsUpDisplay()
{
	if (!IsLocalController()) return;
	HeadsUpDisplay = CreateWidget<UHeadsUpDisplay>(this, HeadsUpDisplayClass);
	if (IsValid(HeadsUpDisplay))
	{
		HeadsUpDisplay->AddToViewport();
	}
}

void ASincePlayerController::ContactTrace()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, Forward)) return;

	const FVector TraceEnd = TraceStart + Forward * ContactTraceLength;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility);

	LastContact = ThisContact;
	ThisContact = HitResult.GetActor();

	if (!ThisContact.IsValid())
	{
		if (IsValid(HeadsUpDisplay))
		{
			HeadsUpDisplay->HideContactMessage();
			HeadsUpDisplay->HideContactName();
		}
	}

	if (ThisContact == LastContact) return;

	if (ThisContact.IsValid())
	{
		UE_LOG(LogSince, Warning, TEXT("Started tracing ThisContact"));

		if (UActorComponent* Highlightable = ThisContact->FindComponentByInterface(UHighlightable::StaticClass()); IsValid(Highlightable))
		{
			IHighlightable::Execute_Highlight(Highlightable);
		}
		
		UContactComponent* ContactComponent = ThisContact->FindComponentByClass<UContactComponent>();
		if (!IsValid(ContactComponent)) return;

		if (IsValid(HeadsUpDisplay))
		{
			HeadsUpDisplay->ShowContactMessage(ContactComponent->GetContactMessage());
			HeadsUpDisplay->ShowContactName(ContactComponent->GetContactName());
		}
	}

	if (LastContact.IsValid())
	{
		UE_LOG(LogSince, Warning, TEXT("Stopped tracing LastContact"));

		if (UActorComponent* Highlightable = LastContact->FindComponentByInterface(UHighlightable::StaticClass()); IsValid(Highlightable))
		{
			IHighlightable::Execute_UnHighlight(Highlightable);
		}
	}
}

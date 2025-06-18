#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

class ACritter;

UENUM(BlueprintType)
enum class EInteractableType : uint8
{
	Pickup UMETA(DisplayName = "Pickup"),
	Device UMETA(DisplayName = "Device"),
	Container UMETA(DisplayName = "Container"),
	NonPlayerCharacter UMETA(DisplayName = "NonPlayerCharacter"),
};

USTRUCT(BlueprintType)
struct FInteractableData
{
	GENERATED_BODY()

	FInteractableData() :

	InteractableType(EInteractableType::Pickup),
	Name(FText::GetEmpty()),
	Action(FText::GetEmpty()),
	InteractionDuration(0.0f)
	{};

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteractableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;

	UPROPERTY(EditInstanceOnly)
	FText Action;

	UPROPERTY(EditInstanceOnly)
	float InteractionDuration;
	
};

class ACritter;

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};
class SINCE_API IInteractionInterface
{
	GENERATED_BODY()

public:
	FInteractableData InteractableData;

	virtual void BeginFocus();
	virtual void EndFocus();
	virtual void BeginInteract();
	virtual void EndInteract();
	virtual void Interact(ACritter* InstigatorCharacter);
	
};

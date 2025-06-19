#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

class ACritter;

UCLASS()
class SINCE_API APickup : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// CONSTRUCTOR
	APickup();

	// OVERRIDES
	virtual void Tick(float DeltaTime) override;
	

protected:
	// BEGIN PLAY
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Pickup")
	TObjectPtr<UStaticMeshComponent> PickupMesh;

	UPROPERTY(EditInstanceOnly, Category="Pickup")
	FInteractableData InstanceInteractableData;

	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	virtual void BeginInteract() override;
	virtual void EndInteract() override;
	virtual void Interact(ACritter* InstigatorCharacter) override;


	
};

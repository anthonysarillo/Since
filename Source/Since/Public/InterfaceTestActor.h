#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "InterfaceTestActor.generated.h"

class ACritter;

UCLASS()
class SINCE_API AInterfaceTestActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// CONSTRUCTOR
	AInterfaceTestActor();

protected:
	// BEGIN PLAY
	virtual void BeginPlay() override;

	// OVERRIDES
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test Actor")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditInstanceOnly, Category="Test Actor")
	FInteractableData InstanceInteractableData;

	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	virtual void BeginInteract() override;
	virtual void EndInteract() override;
	virtual void Interact(ACritter* InstigatorCharacter) override;
};

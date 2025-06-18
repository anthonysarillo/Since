#pragma once

#include "CoreMinimal.h"
#include "CombatInterface.h"
#include "GameFramework/Actor.h"
#include "CombatTestActor.generated.h"

class ACritter;

UCLASS()
class SINCE_API ACombatTestActor : public AActor, public ICombatInterface
{
	GENERATED_BODY()
	
public:	
	// CONSTRUCTOR
	ACombatTestActor();

protected:
	// BEGIN PLAY
	virtual void BeginPlay() override;

	// OVERRIDES
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Test Actor")
	TObjectPtr<USkeletalMeshComponent> Skeleton;

	UPROPERTY(EditInstanceOnly, Category="Test Actor")
	FCombatantData InstancedCombatantData;

	virtual void BeginTargeting() override;
	virtual void EndTargeting() override;
	virtual void BeginCombat() override;
	virtual void EndCombat() override;
	virtual void Combat(ACritter* InstigatorCharacter) override;

};

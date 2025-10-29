// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "ItemManifest.h"
#include "Components/ActorComponent.h"
#include "ItemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class SINCE_API UItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemComponent();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	FItemManifest GetItemManifest() const { return ItemManifest; };

private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory", Replicated)
	FItemManifest ItemManifest;
	
	
};

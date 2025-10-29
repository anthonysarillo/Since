// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Item/ItemManifest.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class SINCE_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override { return true; }

	void SetItemManifest(const FItemManifest& Manifest);
	const FItemManifest& GetItemManifest() const { return ItemManifest.Get<FItemManifest>(); }
	FItemManifest& GetItemManifestMutable() { return ItemManifest.GetMutable<FItemManifest>(); }

private:
	UPROPERTY(VisibleAnywhere, meta=(BaseStruct = "/Script/Since.ItemManifest"), Replicated)
	FInstancedStruct ItemManifest;
	
};

template<typename FragmentType>
const FragmentType* GetFragment(const UInventoryItem* Item, const FGameplayTag& Tag)
{
	if (!IsValid(Item)) return nullptr;

	const FItemManifest& Manifest = Item->GetItemManifest();
	return Manifest.GetFragmentOfTypeWithTag<FragmentType>(Tag);
}


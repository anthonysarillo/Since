// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Types/GridTypes.h"
#include "StructUtils/InstancedStruct.h"
#include "GameplayTagContainer.h"
#include "ItemFragment.h"
#include "ItemManifest.generated.h"

class UInventoryItem;

/**
 * The ItemManifest contains all the necessary data
 * for creating a new InventoryItem
 */

USTRUCT(BlueprintType)
struct SINCE_API FItemManifest
{
	GENERATED_BODY()

	UInventoryItem* Manifest(UObject* NewOuter);
	
	EItemCategory GetItemCategory() const { return ItemCategory; }
	FGameplayTag GetItemType() const { return ItemType; }

	template<typename FragmentType> requires std::derived_from<FragmentType, FItemFragment>
	const FragmentType* GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) const;

	template<typename FragmentType> requires std::derived_from<FragmentType, FItemFragment>
	const FragmentType* GetFragmentOfType() const;
	
private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory,", meta=(ExcludeBaseStruct))
	TArray<TInstancedStruct<FItemFragment>> Fragments;
	
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	EItemCategory ItemCategory {EItemCategory::None};

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	FGameplayTag ItemType;
};

template<typename FragmentType>
requires std::derived_from<FragmentType, FItemFragment>
	const FragmentType* FItemManifest::GetFragmentOfTypeWithTag(const FGameplayTag& FragmentTag) const
{
	for (const TInstancedStruct<FItemFragment>& Fragment : Fragments)
	{
		if (const FragmentType* FragmentPtr = Fragment.GetPtr<FragmentType>())
		{
			if (!FragmentPtr->GetFragmentTag().MatchesTagExact(FragmentTag)) continue;
			return FragmentPtr;
		}
	}
	return nullptr;
}

template <typename FragmentType> requires std::derived_from<FragmentType, FItemFragment>
const FragmentType* FItemManifest::GetFragmentOfType() const
{
	for (const TInstancedStruct<FItemFragment>& Fragment : Fragments)
	{
		if (const FragmentType* FragmentPtr = Fragment.GetPtr<FragmentType>())
		{
			return FragmentPtr;
		}
	}
	return nullptr;
}

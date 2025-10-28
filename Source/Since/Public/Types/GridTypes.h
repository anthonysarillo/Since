// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "GridTypes.generated.h"

/**
 * 
 */

class UInventoryItem;

UENUM(BlueprintType)
enum class EAttributeCategory : uint8
{
	Human,
	Talent,
	Bonus,
	Effort,
	None
};

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Weapon,
	Outfit,
	Provision,
	Misc,
	Ammo,
	None
};

USTRUCT(BlueprintType)
struct FSlotAvailability
{
	GENERATED_BODY()

	FSlotAvailability() {}
	FSlotAvailability(int32 ItemIndex, int32 Room, bool bHasItem) :
	Index(ItemIndex), AmountToFill(Room), bItemAtIndex(bHasItem) {}

	int32 Index {INDEX_NONE};
	int32 AmountToFill {0};
	bool bItemAtIndex {false};
};

USTRUCT(BlueprintType)
struct FSlotAvailabilityResult
{
	GENERATED_BODY()

	FSlotAvailabilityResult() {}

	TWeakObjectPtr<UInventoryItem> Item;
	int32 TotalRoomToFill {0};
	int32 Remainder {0};
	bool bStackable {false};
	TArray<FSlotAvailability> SlotAvailabilities;
};



// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "SinceFastArray.generated.h"

/**
 * 
 */

class UItemComponent;
class UInventoryComponent;
class UInventoryItem;

/**
 * A single Entry in an Inventory
 */
USTRUCT(BlueprintType)
struct FInventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

	FInventoryEntry() {}

private:
	friend UInventoryComponent;
	friend struct FInventoryFastArray;
	
	UPROPERTY()
	TObjectPtr<UInventoryItem> Item = nullptr;
};

/**
 * A list of Inventory Items
 */
USTRUCT(BlueprintType)
struct FInventoryFastArray : public FFastArraySerializer
{
	GENERATED_BODY()

	FInventoryFastArray() : OwnerComponent(nullptr) {}
	FInventoryFastArray(UActorComponent* InOwnerComponent) : OwnerComponent(InOwnerComponent) {}

	TArray<UInventoryItem*> GetAllItems();

	// FFastArraySerializer contract
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	// End of FFastArraySerializer contract

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
	{
		return FastArrayDeltaSerialize<FInventoryEntry, FInventoryFastArray>(Entries, DeltaParams, *this);
	}

	UInventoryItem* AddEntry(UItemComponent* ItemComponent);
	UInventoryItem* AddEntry(UInventoryItem* Item);
	void RemoveEntry(UInventoryItem* Item);

private:
	friend UInventoryComponent;
	
	// Replicated list of Items
	UPROPERTY()
	TArray<FInventoryEntry> Entries;
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;
};

template<>
struct TStructOpsTypeTraits<FInventoryFastArray> : TStructOpsTypeTraitsBase2<FInventoryFastArray>
{
	enum { WithNetDeltaSerializer = true };
};


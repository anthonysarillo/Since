// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item/ItemManifest.h"
#include "Types/GridTypes.h"
#include "InventoryGrid.generated.h"

class USlottedItem;
class UItemComponent;
class UInventoryComponent;
class UScrollBox;
class UCanvasPanel;
class UInventoryGridSlot;
/**
 * Ended on lecture 36 got items adding into scroll boxes with categories
 */
UCLASS()
class SINCE_API UInventoryGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	
	EItemCategory GetItemCategory() const { return ItemCategory; }
	FSlotAvailabilityResult HasRoomForItem(const UItemComponent* ItemComponent);
	
	UFUNCTION()
	void AddItem(UInventoryItem* Item);

private:
	TWeakObjectPtr<UInventoryComponent> InventoryComponent;
	
	//void ConstructInventoryGrid();

	FSlotAvailabilityResult HasRoomForItem(const UInventoryItem* Item);
	FSlotAvailabilityResult HasRoomForItem(const FItemManifest& Manifest);
	void AddItemToIndices(const FSlotAvailabilityResult& Result, UInventoryItem* NewItem);
	void AddItemAtIndex(UInventoryItem* Item, const int32 Index, const bool bStackable, const int32 StackAmount);
	USlottedItem* CreateSlottedItem(UInventoryItem* Item,
		const bool bStackable,
		const int32 StackAmount,
		const FGridFragment* GridFragment,
		//const FWidgetFragment* WidgetFragment,
		const int32 Index);
	void AddSlottedItemToScrollBox(const int32 Index, const FGridFragment* GridFragment, USlottedItem* SlottedItem) const;
	bool IsIndexClaimed(const TSet<int32>& CheckedIndices, const int32 Index) const;
	bool HasRoomAtIndex(const USlottedItem* SlottedItem, const FIntPoint& Dimensions);
	FIntPoint GetItemDimensions(const FItemManifest& Manifest) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Since|Inventory")
	EItemCategory ItemCategory;

	UPROPERTY()
	TArray<TObjectPtr<UInventoryGridSlot>> InventoryGridSlots;

	UPROPERTY(EditDefaultsOnly, Category="Since|Inventory")
	TSubclassOf<UInventoryGridSlot> InventoryGridSlotClass;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UScrollBox> InventoryGridScrollBox;

	UPROPERTY(EditDefaultsOnly, Category="Since|Inventory")
	TSubclassOf<USlottedItem> SlottedItemClass;

	UPROPERTY()
	TMap<int32, TObjectPtr<USlottedItem>> SlottedItems;
	
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 Rows;
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 Columns;
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	float TileSize;

	bool MatchesCategory(const UInventoryItem* Item) const;
};

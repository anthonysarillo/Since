// Since - 2025


#include "UI/InventoryGrid.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ScrollBox.h"
#include "Components/ScrollBoxSlot.h"
#include "Inventory/InventoryComponent.h"
#include "Item/FragmentTags.h"
#include "Item/InventoryItem.h"
#include "Item/ItemComponent.h"
#include "Item/ItemManifest.h"
#include "Since/Since.h"
#include "Statics/SinceStatics.h"
#include "Statics/WidgetStatics.h"
#include "UI/InventoryGridSlot.h"
#include "UI/SlottedItem.h"

void UInventoryGrid::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//ConstructInventoryGrid();

	InventoryComponent = USinceStatics::GetInventoryComponent(GetOwningPlayer());
	InventoryComponent->OnItemAdded.AddDynamic(this, &ThisClass::AddItem);
}

FSlotAvailabilityResult UInventoryGrid::HasRoomForItem(const UItemComponent* ItemComponent)
{
	return HasRoomForItem(ItemComponent->GetItemManifest());
}

FSlotAvailabilityResult UInventoryGrid::HasRoomForItem(const UInventoryItem* Item)
{
	return HasRoomForItem(Item->GetItemManifest());
}

FSlotAvailabilityResult UInventoryGrid::HasRoomForItem(const FItemManifest& Manifest)
{
	FSlotAvailabilityResult Result;

	// Determine if the Item is stackable.
	const FStackableFragment* StackableFragment = Manifest.GetFragmentOfType<FStackableFragment>();
	Result.bStackable = StackableFragment != nullptr;
	// Determine how many stacks to add.
	const int32 MaxStackSize = StackableFragment ? StackableFragment->GetMaxStackSize() : 1;
	int32 AmountToFill = StackableFragment ? StackableFragment->GetStackCount() : 1;

	TSet<int32> CheckedIndices;
	// for each slotted item
	for (const auto& SlottedItem : SlottedItems)
	{
		// if we dont have any more to fill, break out of the loop
		if (AmountToFill == 0) break;
		// is this index claimed yet?
		 
		// can the item fit here? (i.e, is it out of grid bounds)
		
		
		// Is there room at this index? (are there other items in the way)
		// check any other important conditions
			// index claimed?
			// has valid item?
			// is this item the same type as item were trying to add?
			// if so, is this a stackable item?
			// if stackable, is this slot at maxstacksize already?
		// How much to fill?
		// Update the amount left to fill
	}
		
	// how much is the remainder?

	return Result;
}

bool UInventoryGrid::HasRoomAtIndex(const USlottedItem* SlottedItem, const FIntPoint& Dimensions)
{
	bool bHasRoomAtIndex = true;
	
	return bHasRoomAtIndex;
}

FIntPoint UInventoryGrid::GetItemDimensions(const FItemManifest& Manifest) const
{
	const FGridFragment* GridFragment = Manifest.GetFragmentOfType<FGridFragment>();
	return GridFragment->GetGridSize();
}

void UInventoryGrid::AddItem(UInventoryItem* Item)
{
	if (!MatchesCategory(Item)) return;

	UE_LOG(LogSince, Warning, TEXT("UInventoryGrid::AddItem"));

	FSlotAvailabilityResult Result = HasRoomForItem(Item);
	AddItemToIndices(Result, Item);
}

void UInventoryGrid::AddItemToIndices(const FSlotAvailabilityResult& Result, UInventoryItem* NewItem)
{
	for (const auto& Availability : Result.SlotAvailabilities)
	{
		AddItemAtIndex(NewItem, Availability.Index, Result.bStackable, Availability.AmountToFill);
	}
}

void UInventoryGrid::AddItemAtIndex(UInventoryItem* Item, const int32 Index, const bool bStackable,
	const int32 StackAmount)
{
	const FGridFragment* GridFragment = GetFragment<FGridFragment>(Item, Fragment::Grid);
	//const FWidgetFragment* WidgetFragment = GetFragment<FWidgetFragment>(Item, Fragment::Widget);
	if (!GridFragment) return; //|| !WidgetFragment

	USlottedItem* SlottedItem = CreateSlottedItem(Item, bStackable, StackAmount, GridFragment, Index); //WidgetFragment
	AddSlottedItemToScrollBox(Index, GridFragment, SlottedItem);

	SlottedItems.Add(Index, SlottedItem);
}

USlottedItem* UInventoryGrid::CreateSlottedItem(UInventoryItem* Item, const bool bStackable, const int32 StackAmount,
	const FGridFragment* GridFragment, const int32 Index) //const FWidgetFragment* WidgetFragment*, 
{
	USlottedItem* SlottedItem = CreateWidget<USlottedItem>(GetOwningPlayer(), SlottedItemClass);
	SlottedItem->SetInventoryItem(Item);
	SlottedItem->SetGridIndex(Index);
	SlottedItem->SetIsStackable(bStackable);
	const int32 StackUpdateAmount = bStackable ? StackAmount : 0;
	SlottedItem->UpdateStackCount(StackUpdateAmount);

	return SlottedItem;
}

void UInventoryGrid::AddSlottedItemToScrollBox(const int32 Index, const FGridFragment* GridFragment,
	USlottedItem* SlottedItem) const
{
	InventoryGridScrollBox->AddChild(SlottedItem);
	UScrollBoxSlot* ScrollBoxSlot = UWidgetLayoutLibrary::SlotAsScrollBoxSlot(SlottedItem);
	ScrollBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	ScrollBoxSlot->SetPadding(FMargin(5, 5, 5, 5));
	ScrollBoxSlot->SetHorizontalAlignment(HAlign_Fill);
	ScrollBoxSlot->SetVerticalAlignment(VAlign_Top);
	UWidgetStatics::GetPositionFromIndex(Index, Columns);
}

bool UInventoryGrid::IsIndexClaimed(const TSet<int32>& CheckedIndices, const int32 Index) const
{
	return CheckedIndices.Contains(Index);
}

// void UInventoryGrid::ConstructInventoryGrid()
// {
// 	InventoryGridSlots.Reserve(Rows * Columns);
//
// 	for (int32 j = 0; j < Rows; ++j)
// 	{
// 		for (int32 i = 0; i < Columns; ++i)
// 		{
// 			UInventoryGridSlot* GridSlot = CreateWidget<UInventoryGridSlot>(this, InventoryGridSlotClass);
// 			InventoryGridScrollBox->AddChild(GridSlot);
//
// 			const FIntPoint TilePosition(i, j);
// 			GridSlot->SetTileIndex(UWidgetStatics::GetIndexFromPosition(FIntPoint(i, j), Columns));
//
// 			UScrollBoxSlot* ScrollBoxSlot = UWidgetLayoutLibrary::SlotAsScrollBoxSlot(GridSlot);
// 			ScrollBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
// 			ScrollBoxSlot->SetPadding(FMargin(5, 5, 5, 5));
// 			ScrollBoxSlot->SetHorizontalAlignment(HAlign_Fill);
// 			ScrollBoxSlot->SetVerticalAlignment(VAlign_Top);
//
// 			InventoryGridSlots.Add(GridSlot);
// 		}
// 	}
// }

bool UInventoryGrid::MatchesCategory(const UInventoryItem* Item) const
{
	return Item->GetItemManifest().GetItemCategory() == ItemCategory;
}

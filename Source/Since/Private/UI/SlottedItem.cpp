// Since - 2025


#include "UI/SlottedItem.h"
#include "Components/TextBlock.h"
#include "Item/InventoryItem.h"

void USlottedItem::SetInventoryItem(UInventoryItem* Item)
{
	InventoryItem = Item;
}

void USlottedItem::UpdateStackCount(int32 StackCount)
{
	if (StackCount > 0)
	{
		SlottedItemStackCount->SetVisibility(ESlateVisibility::Visible);
		SlottedItemStackCount->SetText(FText::AsNumber(StackCount));
	}
	else
	{
		SlottedItemStackCount->SetVisibility(ESlateVisibility::Collapsed);
	}
}

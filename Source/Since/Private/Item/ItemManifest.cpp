// Since - 2025


#include "Item/ItemManifest.h"
#include "Item/InventoryItem.h"


UInventoryItem* FItemManifest::Manifest(UObject* NewOuter)
{
	UInventoryItem* Item = NewObject<UInventoryItem>(NewOuter, UInventoryItem::StaticClass());
	Item->SetItemManifest(*this);

	return Item;
}

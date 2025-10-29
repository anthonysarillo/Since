// Since - 2025


#include "Statics/SinceStatics.h"
#include "Inventory/InventoryComponent.h"
#include "Item/ItemComponent.h"

UInventoryComponent* USinceStatics::GetInventoryComponent(const APlayerController* PlayerController)
{
	if (!IsValid(PlayerController)) return nullptr;

	UInventoryComponent* InventoryComponent = PlayerController->FindComponentByClass<UInventoryComponent>();
	return InventoryComponent;
}

EItemCategory USinceStatics::GetItemCategoryFromItemComponent(UItemComponent* ItemComponent)
{
	if (!IsValid(ItemComponent)) return EItemCategory::None;
	return ItemComponent->GetItemManifest().GetItemCategory();
}

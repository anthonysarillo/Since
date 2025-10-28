// Since - 2025


#include "Statics/SinceStatics.h"
#include "Inventory/InventoryComponent.h"

UInventoryComponent* USinceStatics::GetInventoryComponent(const APlayerController* PlayerController)
{
	if (!IsValid(PlayerController)) return nullptr;

	UInventoryComponent* InventoryComponent = PlayerController->FindComponentByClass<UInventoryComponent>();
	return InventoryComponent;
}

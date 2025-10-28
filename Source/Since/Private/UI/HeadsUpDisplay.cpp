// Since - 2025


#include "UI/HeadsUpDisplay.h"
#include "Inventory/InventoryComponent.h"
#include "Statics/SinceStatics.h"
#include "UI/MaxBackpackMessage.h"

void UHeadsUpDisplay::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UInventoryComponent* InventoryComponent = USinceStatics::GetInventoryComponent(GetOwningPlayer());
	if (IsValid(InventoryComponent))
	{
		InventoryComponent->OnMaxBackpack.AddDynamic(this, &ThisClass::OnMaxBackpack);
	}
}

void UHeadsUpDisplay::OnMaxBackpack()
{
	if (!IsValid(MaxBackpackMessage)) return;
	MaxBackpackMessage->SetMaxBackpackMessage(FText::FromString("At Max Backpack"));
}

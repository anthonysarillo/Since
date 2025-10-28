// Since - 2025


#include "UI/InventoryMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "UI/AttributeGrid.h"
#include "UI/InventoryGrid.h"

void UInventoryMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	HumanButton->OnClicked.AddDynamic(this, &ThisClass::ShowHumanGrid);
	TalentsButton->OnClicked.AddDynamic(this, &ThisClass::ShowTalentsGrid);
	BonusesButton->OnClicked.AddDynamic(this, &ThisClass::ShowBonusesGrid);
	EffortsButton->OnClicked.AddDynamic(this, &ThisClass::ShowEffortsGrid);
	WeaponsButton->OnClicked.AddDynamic(this, &ThisClass::ShowWeaponsGrid);
	OutfitButton->OnClicked.AddDynamic(this, &ThisClass::ShowOutfitGrid);
	ProvisionsButton->OnClicked.AddDynamic(this, &ThisClass::ShowProvisionsGrid);
	MiscButton->OnClicked.AddDynamic(this, &ThisClass::ShowMiscGrid);
	AmmoButton->OnClicked.AddDynamic(this, &ThisClass::ShowAmmoGrid);
	ShowHumanGrid();
}

FSlotAvailabilityResult UInventoryMenu::HasRoomForItem(UItemComponent* ItemComponent) const
{
	return FSlotAvailabilityResult();
}

void UInventoryMenu::ShowHumanGrid()
{
	SetAttributeGrid(HumanGrid, HumanButton);
}

void UInventoryMenu::ShowTalentsGrid()
{
	SetAttributeGrid(TalentsGrid, TalentsButton);
}

void UInventoryMenu::ShowBonusesGrid()
{
	SetAttributeGrid(BonusesGrid, BonusesButton);
}

void UInventoryMenu::ShowEffortsGrid()
{
	SetAttributeGrid(EffortsGrid, EffortsButton);
}

void UInventoryMenu::ShowWeaponsGrid()
{
	SetInventoryGrid(WeaponsGrid, WeaponsButton);
}

void UInventoryMenu::ShowOutfitGrid()
{
	SetInventoryGrid(OutfitGrid, OutfitButton);
}

void UInventoryMenu::ShowProvisionsGrid()
{
	SetInventoryGrid(ProvisionsGrid, ProvisionsButton);
}

void UInventoryMenu::ShowMiscGrid()
{
	SetInventoryGrid(MiscGrid, MiscButton);
}

void UInventoryMenu::ShowAmmoGrid()
{
	SetInventoryGrid(AmmoGrid, AmmoButton);
}

void UInventoryMenu::DisableButton(UButton* Button)
{
	HumanButton->SetIsEnabled(true);
	TalentsButton->SetIsEnabled(true);
	BonusesButton->SetIsEnabled(true);
	EffortsButton->SetIsEnabled(true);
	WeaponsButton->SetIsEnabled(true);
	OutfitButton->SetIsEnabled(true);
	ProvisionsButton->SetIsEnabled(true);
	MiscButton->SetIsEnabled(true);
	AmmoButton->SetIsEnabled(true);
	Button->SetIsEnabled(false);
}

void UInventoryMenu::SetAttributeGrid(UAttributeGrid* Grid, UButton* Button)
{
	DisableButton(Button);

	InventoryMenuSwitcher->SetActiveWidget(Grid);
}

void UInventoryMenu::SetInventoryGrid(UInventoryGrid* Grid, UButton* Button)
{
	DisableButton(Button);

	InventoryMenuSwitcher->SetActiveWidget(Grid);
}

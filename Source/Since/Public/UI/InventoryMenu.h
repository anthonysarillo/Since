// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "InventoryBase.h"
#include "InventoryMenu.generated.h"

class UButton;
class UInventoryGrid;
class UAttributeGrid;
class UWidgetSwitcher;
/**
 * 
 */
UCLASS()
class SINCE_API UInventoryMenu : public UInventoryBase
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	virtual FSlotAvailabilityResult HasRoomForItem(UItemComponent* ItemComponent) const override;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> InventoryMenuSwitcher;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAttributeGrid> HumanGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAttributeGrid> TalentsGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAttributeGrid> BonusesGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAttributeGrid> EffortsGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInventoryGrid> WeaponsGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInventoryGrid> OutfitGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInventoryGrid> ProvisionsGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInventoryGrid> MiscGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UInventoryGrid> AmmoGrid;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> HumanButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> TalentsButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> BonusesButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> EffortsButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> WeaponsButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OutfitButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> ProvisionsButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> MiscButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> AmmoButton;

	UFUNCTION()
	void ShowHumanGrid();

	UFUNCTION()
	void ShowTalentsGrid();

	UFUNCTION()
	void ShowBonusesGrid();

	UFUNCTION()
	void ShowEffortsGrid();

	UFUNCTION()
	void ShowWeaponsGrid();

	UFUNCTION()
	void ShowOutfitGrid();

	UFUNCTION()
	void ShowProvisionsGrid();

	UFUNCTION()
	void ShowMiscGrid();

	UFUNCTION()
	void ShowAmmoGrid();

	void DisableButton(UButton* Button);
	void SetAttributeGrid(UAttributeGrid* Grid, UButton* Button);
	void SetInventoryGrid(UInventoryGrid* Grid, UButton* Button);

	
};

// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/GridTypes.h"
#include "InventoryGrid.generated.h"

class UScrollBox;
class UCanvasPanel;
class UInventoryGridSlot;
/**
 * 
 */
UCLASS()
class SINCE_API UInventoryGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	
	EItemCategory GetItemCategory() const { return ItemCategory; };

private:
	void ConstructInventoryGrid();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Since|Inventory")
	EItemCategory ItemCategory;

	UPROPERTY()
	TArray<TObjectPtr<UInventoryGridSlot>> InventoryGridSlots;

	UPROPERTY(EditDefaultsOnly, Category="Since|Inventory")
	TSubclassOf<UInventoryGridSlot> InventoryGridSlotClass;

	//UPROPERTY(meta=(BindWidget))
	//TObjectPtr<UCanvasPanel> InventoryGridCanvasPanel;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UScrollBox> InventoryGridScrollBox;
	
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 Rows;
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 Columns;
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	float TileSize;
};

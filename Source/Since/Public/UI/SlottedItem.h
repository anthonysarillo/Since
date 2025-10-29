// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlottedItem.generated.h"

class UInventoryItem;
class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class SINCE_API USlottedItem : public UUserWidget
{
	GENERATED_BODY()

public:
	bool IsStackable() const { return bIsStackable; }
	void SetIsStackable(bool bStackable) { bIsStackable = bStackable; }
	UButton* GetSlottedItemButton() const { return SlottedItemButton; }
	UTextBlock* GetSlottedItemText() const { return SlottedItemText; }
	void SetSlottedItemText(UTextBlock* Text) { SlottedItemText = Text; }
	int32 GetGridIndex() const { return GridIndex; }
	void SetGridIndex(int32 Index) { GridIndex = Index; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	void SetGridDimensions(FIntPoint Dimensions) { GridDimensions = Dimensions; }
	UInventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	void SetInventoryItem(UInventoryItem* Item);
	void UpdateStackCount(int32 StackCount);
	
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> SlottedItemButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> SlottedItemText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> SlottedItemStackCount;

	int32 GridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<UInventoryItem> InventoryItem;
	bool bIsStackable {false};
};

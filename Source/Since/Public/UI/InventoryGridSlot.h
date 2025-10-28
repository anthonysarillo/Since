// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryGridSlot.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class SINCE_API UInventoryGridSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	int32 GetTileIndex() const { return TileIndex; }
	void SetTileIndex(int32 Index) { TileIndex = Index; }

private:
	int32 TileIndex;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> GridSlot;
	
};

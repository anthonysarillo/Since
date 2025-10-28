// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/GridTypes.h"
#include "InventoryBase.generated.h"

class UItemComponent;
/**
 * 
 */
UCLASS()
class SINCE_API UInventoryBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual FSlotAvailabilityResult HasRoomForItem(UItemComponent* ItemComponent) const { return FSlotAvailabilityResult(); }
};

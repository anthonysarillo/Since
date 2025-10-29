// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/GridTypes.h"
#include "SinceStatics.generated.h"

class UItemComponent;
class UInventoryComponent;
/**
 * 
 */
UCLASS()
class SINCE_API USinceStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Since|Inventory")
	static UInventoryComponent* GetInventoryComponent(const APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Since|Inventory")
	static EItemCategory GetItemCategoryFromItemComponent(UItemComponent* ItemComponent);
};

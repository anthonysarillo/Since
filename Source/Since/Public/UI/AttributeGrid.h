// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/GridTypes.h"
#include "AttributeGrid.generated.h"

/**
 * 
 */
UCLASS()
class SINCE_API UAttributeGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	EAttributeCategory GetAttributeCategory() const { return AttributeCategory; };

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Since|Inventory")
	EAttributeCategory AttributeCategory;
};

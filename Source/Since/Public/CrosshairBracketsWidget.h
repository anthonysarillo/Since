#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CrosshairBracketsWidget.generated.h"

class UTextBlock;
struct FCombatantData;
struct FInteractableData;

UCLASS()
class SINCE_API UCrosshairBracketsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	

protected:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget), Category="CrosshairBrackets Widget | Data")
	TObjectPtr<UTextBlock> Brackets;
	
};

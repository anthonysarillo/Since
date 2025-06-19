#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CrosshairWidget.generated.h"

class UTextBlock;

UCLASS()
class SINCE_API UCrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget), Category="CrosshairBrackets Widget | Data")
	TObjectPtr<UTextBlock> Crosshair;
	
};

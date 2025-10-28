// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeadsUpDisplay.generated.h"

class UMaxBackpackMessage;
/**
 * 
 */
UCLASS()
class SINCE_API UHeadsUpDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, Category="Since|Contact")
	void ShowContactMessage(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent, Category="Since|Contact")
	void HideContactMessage();

	UFUNCTION(BlueprintImplementableEvent, Category="Since|Contact")
	void ShowContactName(const FText& Name);

	UFUNCTION(BlueprintImplementableEvent, Category="Since|Contact")
	void HideContactName();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMaxBackpackMessage> MaxBackpackMessage;

	UFUNCTION()
	void OnMaxBackpack();
};

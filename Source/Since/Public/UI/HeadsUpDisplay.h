// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeadsUpDisplay.generated.h"

class UTextBlock;
class UImage;
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

	UImage* GetCrosshair() const { return Crosshair; }
	UTextBlock* GetBrackets() const { return Brackets; }

private:
	UPROPERTY(meta = (BindWidget), meta=(AllowPrivateAccess="true"), BlueprintReadOnly)
	TObjectPtr<UImage> Crosshair;

	UPROPERTY(meta = (BindWidget), meta=(AllowPrivateAccess="true"), BlueprintReadOnly)
	TObjectPtr<UTextBlock> Brackets;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMaxBackpackMessage> MaxBackpackMessage;

	UFUNCTION()
	void OnMaxBackpack();
};

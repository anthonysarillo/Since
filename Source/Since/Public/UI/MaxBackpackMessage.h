// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MaxBackpackMessage.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class SINCE_API UMaxBackpackMessage : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Since|Inventory")
	void ShowMaxBackpackMessage();

	UFUNCTION(BlueprintImplementableEvent, Category="Since|Inventory")
	void HideMaxBackpackMessage();

	void SetMaxBackpackMessage(const FText& Message);
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxBackpackMessage;

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	float MaxBackpackMessageLifetime {3.f};

	FTimerHandle MaxBackpackMessageTimer;
	bool bIsMaxBackpackMessageActive {false};
	
};

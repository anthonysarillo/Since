#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"

class UTextBlock;
struct FInteractableData;
class ACritter;

UCLASS()
class SINCE_API UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Interaction Widget | Critter Reference")
	TObjectPtr<ACritter> CritterRef;

	void UpdateWidget(const FInteractableData* InteractableData) const;

protected:
	// OVERRIDES
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget), Category="Interaction Widget | Data")
	TObjectPtr<UTextBlock> Name;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget), Category="Interaction Widget | Data")
	TObjectPtr<UTextBlock> Action;
	
};

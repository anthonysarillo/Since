#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatWidget.generated.h"

struct FCombatantData;
class UTextBlock;
class ACritter;

UCLASS()
class SINCE_API UCombatWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Combat Widget | Critter Reference")
	TObjectPtr<ACritter> CritterRef;

	void UpdateCombatWidget(const FCombatantData* CombatantData) const;

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget), Category="Combat Widget | Data")
	TObjectPtr<UTextBlock> Name;
};

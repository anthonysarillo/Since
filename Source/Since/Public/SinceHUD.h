#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SinceHUD.generated.h"

class UCrosshairWidget;
struct FCombatantData;
class UCombatWidget;
class UInteractionWidget;
struct FInteractableData;

UCLASS()
class SINCE_API ASinceHUD : public AHUD
{
	GENERATED_BODY()

public:
	// CONSTRUCTOR
	ASinceHUD();

	// CROSSHAIR WIDGET
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UCrosshairWidget> CrosshairWidgetClass;

	void ShowCrosshairWidget() const;
	void HideCrosshairWidget() const;

	// INTERACTION WIDGET
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;
	
	void ShowInteractionWidget() const;
	void HideInteractionWidget() const;
	void UpdateInteractionWidget(const FInteractableData* InteractableData) const;

	// COMBAT WIDGET
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UCombatWidget> CombatWidgetClass;

	void ShowCombatWidget() const;
	void HideCombatWidget() const;
	void UpdateCombatWidget(const FCombatantData* CombatantData) const;

protected:
	// BEGIN PLAY
	virtual void BeginPlay() override;

	// CROSSHAIR WIDGET
	UPROPERTY()
	TObjectPtr<UCrosshairWidget> CrosshairWidget;

	// INTERACTION WIDGET
	UPROPERTY()
	TObjectPtr<UInteractionWidget> InteractionWidget;

	// COMBAT WIDGET
	UPROPERTY()
	TObjectPtr<UCombatWidget> CombatWidget;
};

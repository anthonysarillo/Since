// GAME
#include "SinceHUD.h"
#include "CombatWidget.h"
#include "CrosshairBracketsWidget.h"
#include "CrosshairWidget.h"
#include "InteractionWidget.h"

// ENGINE

ASinceHUD::ASinceHUD()
{
}

void ASinceHUD::BeginPlay()
{
	Super::BeginPlay();

	if (CrosshairWidgetClass)
	{
		CrosshairWidget = CreateWidget<UCrosshairWidget>(GetWorld(), CrosshairWidgetClass);
		CrosshairWidget->AddToViewport(4);
		CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
	}

	if (CrosshairBracketsClass)
	{
		CrosshairBracketsWidget = CreateWidget<UCrosshairBracketsWidget>(GetWorld(), CrosshairBracketsClass);
		CrosshairBracketsWidget->AddToViewport(3);
		CrosshairBracketsWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (InteractionWidgetClass)
	{
		InteractionWidget = CreateWidget<UInteractionWidget>(GetWorld(), InteractionWidgetClass);
		InteractionWidget->AddToViewport(2);
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (CombatWidgetClass)
	{
		CombatWidget = CreateWidget<UCombatWidget>(GetWorld(), CombatWidgetClass);
		CombatWidget->AddToViewport(1);
		CombatWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

	void ASinceHUD::ShowCrosshairWidget() const
{
	if (CrosshairWidget)
	{
		CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void ASinceHUD::HideCrosshairWidget() const
{
	if (CrosshairWidget)
	{
		CrosshairWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ASinceHUD::ShowBrackets() const
{
	if (CrosshairBracketsWidget)
	{
		CrosshairBracketsWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void ASinceHUD::HideBrackets() const
{
	if (CrosshairBracketsWidget)
	{
		CrosshairBracketsWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ASinceHUD::ShowInteractionWidget() const
{
	if (InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void ASinceHUD::HideInteractionWidget() const
{
	if (InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ASinceHUD::UpdateInteractionWidget(const FInteractableData* InteractableData) const
{
	if (InteractionWidget)
	{
		if (InteractionWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		}
		InteractionWidget->UpdateWidget(InteractableData);
	}
}

void ASinceHUD::ShowCombatWidget() const
{
	if (CombatWidget)
	{
		CombatWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void ASinceHUD::HideCombatWidget() const
{
	if (CombatWidget)
	{
		CombatWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ASinceHUD::UpdateCombatWidget(const FCombatantData* CombatantData) const
{
	if (CombatWidget)
	{
		if (CombatWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			CombatWidget->SetVisibility(ESlateVisibility::Visible);
		}
		CombatWidget->UpdateCombatWidget(CombatantData);
	}
}



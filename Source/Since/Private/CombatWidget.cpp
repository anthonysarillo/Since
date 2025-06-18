// GAME
#include "CombatWidget.h"
#include "CombatInterface.h"

// ENGINE
#include "Components/TextBlock.h"

void UCombatWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCombatWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCombatWidget::UpdateCombatWidget(const FCombatantData* CombatantData) const
{
	switch (CombatantData->CombatantType)
	{
	case ECombatantType::Enemy:
		break;
	case ECombatantType::Creature:
		break;
	default: ;
	}
	Name->SetText(CombatantData->Name);
}



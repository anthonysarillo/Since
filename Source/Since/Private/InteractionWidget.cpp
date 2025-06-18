// GAME
#include "InteractionWidget.h"
#include "InteractionInterface.h"

// ENGINE
#include "Components/TextBlock.h"

void UInteractionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UInteractionWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInteractionWidget::UpdateWidget(const FInteractableData* InteractableData) const
{
	switch (InteractableData->InteractableType)
	{
	case EInteractableType::Pickup:
		break;
	case EInteractableType::Device:
		break;
	case EInteractableType::Container:
		break;
	case EInteractableType::NonPlayerCharacter:
		break;
	default: ;
	}
	Name->SetText(InteractableData->Name);
	Action->SetText(InteractableData->Action);
}




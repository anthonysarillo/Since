// Since - 2025


#include "Item/ItemComponent.h"
#include "Net/UnrealNetwork.h"


UItemComponent::UItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	
}

void UItemComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemManifest);
}





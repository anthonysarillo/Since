// Since - 2025


#include "GAS/SinceAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

USinceAttributeSet::USinceAttributeSet()
{
	InitHitPoints(200.f);
	InitHitPointsMax(200.f);
	InitEnergy(100.f);
	InitEnergyMax(100.f);
}

void USinceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void USinceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void USinceAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, HitPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, HitPointsMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Energy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, EnergyMax, COND_None, REPNOTIFY_Always);
}

// Primary OnRep

// Derived OnRep
void USinceAttributeSet::OnRep_HitPoints(const FGameplayAttributeData& OldHitPoints)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, HitPoints, OldHitPoints);
}

void USinceAttributeSet::OnRep_HitPointsMax(const FGameplayAttributeData& OldHitPointsMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, HitPointsMax, OldHitPointsMax);
}

void USinceAttributeSet::OnRep_Energy(const FGameplayAttributeData& OldEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Energy, OldEnergy);
}

void USinceAttributeSet::OnRep_EnergyMax(const FGameplayAttributeData& OldEnergyMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, EnergyMax, OldEnergyMax);
}

// Talent OnRep

// Bonus OnRep

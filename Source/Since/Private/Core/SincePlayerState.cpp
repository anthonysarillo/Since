// Since - 2025


#include "Core/SincePlayerState.h"
#include "GAS/SinceAbilitySystemComponent.h"
#include "GAS/SinceAttributeSet.h"

ASincePlayerState::ASincePlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<USinceAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USinceAttributeSet>("AttributeSet");
}

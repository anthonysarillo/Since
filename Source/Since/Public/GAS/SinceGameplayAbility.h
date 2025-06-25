#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Since/Since.h"
#include "SinceGameplayAbility.generated.h"

UCLASS()
class SINCE_API USinceGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	// Constructor
	USinceGameplayAbility();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	ESinceAbilityInputID AbilityInputID = ESinceAbilityInputID::None;
	
};

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Bonuses.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class SINCE_API UBonuses : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor
	UBonuses();

	// Bonuses - (Perks in Fallout)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Vaccinated; // HitPoints Modifier - HitPointsMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, Vaccinated)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData YouAreWhatYouEat; // HitPoints Modifier - HitPointsMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, YouAreWhatYouEat)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData GetOffMe; // Threshold Modifier - Threshold - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, GetOffMe)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData WeightOfTheWorld; // BackPack Modifier - BackPackMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, WeightOfTheWorld)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData PluggedIn; // Energy Modifier - EnergyMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, PluggedIn)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData IWouldWalk; // Energy Modifier - EnergyMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, IWouldWalk)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData SteadyHands; // Crit Modifier - CritMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, SteadyHands)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HoleInOne; // Crit Modifier - CritMax - Permanent
	ATTRIBUTE_ACCESSORS(UBonuses, HoleInOne)
	
};

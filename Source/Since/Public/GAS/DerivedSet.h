#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "DerivedSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SINCE_API UDerivedSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor
	UDerivedSet();

	// Overrides

	// Derived Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DudeLevel;
	ATTRIBUTE_ACCESSORS(UDerivedSet, DudeLevel)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DudeLevelMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, DudeLevelMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData XP;
	ATTRIBUTE_ACCESSORS(UDerivedSet, XP)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData XPMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, XPMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HitPoints;
	ATTRIBUTE_ACCESSORS(UDerivedSet, HitPoints)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HitPointsMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, HitPointsMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HitPointsRegenRate;
	ATTRIBUTE_ACCESSORS(UDerivedSet, HitPointsRegenRate)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Energy)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData EnergyMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, EnergyMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData EnergyRegenRate;
	ATTRIBUTE_ACCESSORS(UDerivedSet, EnergyRegenRate)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Backpack;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Backpack)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData BackpackMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, BackpackMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Crit;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Crit)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CritMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, CritMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Resistance;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Resistance)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Threshold;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Threshold)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Damage)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData UnarmedDamage;
	ATTRIBUTE_ACCESSORS(UDerivedSet, UnarmedDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MeleeDamage;
	ATTRIBUTE_ACCESSORS(UDerivedSet, MeleeDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ReloadSpeed;
	ATTRIBUTE_ACCESSORS(UDerivedSet, ReloadSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(UDerivedSet, MoveSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData TalentPoints;
	ATTRIBUTE_ACCESSORS(UDerivedSet, TalentPoints)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData TalentPointsMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, TalentPointsMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Thirst;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Thirst)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ThirstMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, ThirstMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Exhaustion;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Exhaustion)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ExhaustionMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, ExhaustionMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(UDerivedSet, Hunger)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HungerMax;
	ATTRIBUTE_ACCESSORS(UDerivedSet, HungerMax)

};

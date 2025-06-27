// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Talents.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SINCE_API UTalents : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor
	UTalents();

	// Overrides
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// Talents - (Skills in Fallout)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Fisticuffs;
	ATTRIBUTE_ACCESSORS(UTalents, Fisticuffs)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData FisticuffsMax;
	ATTRIBUTE_ACCESSORS(UTalents, FisticuffsMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CloseQuarters;
	ATTRIBUTE_ACCESSORS(UTalents, CloseQuarters)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CloseQuartersMax;
	ATTRIBUTE_ACCESSORS(UTalents, CloseQuartersMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Firearms;
	ATTRIBUTE_ACCESSORS(UTalents, Firearms)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData FirearmsMax;
	ATTRIBUTE_ACCESSORS(UTalents, FirearmsMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Stealth;
	ATTRIBUTE_ACCESSORS(UTalents, Stealth)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData StealthMax;
	ATTRIBUTE_ACCESSORS(UTalents, StealthMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Haggle;
	ATTRIBUTE_ACCESSORS(UTalents, Haggle)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HaggleMax;
	ATTRIBUTE_ACCESSORS(UTalents, HaggleMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Gab;
	ATTRIBUTE_ACCESSORS(UTalents, Gab)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData GabMax;
	ATTRIBUTE_ACCESSORS(UTalents, GabMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Remedy;
	ATTRIBUTE_ACCESSORS(UTalents, Remedy)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData RemedyMax;
	ATTRIBUTE_ACCESSORS(UTalents, RemedyMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData BeeNee;
	ATTRIBUTE_ACCESSORS(UTalents, BeeNee)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData BeeNeeMax;
	ATTRIBUTE_ACCESSORS(UTalents, BeeNeeMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Restore;
	ATTRIBUTE_ACCESSORS(UTalents, Restore)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData RestoreMax;
	ATTRIBUTE_ACCESSORS(UTalents, RestoreMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Grit;
	ATTRIBUTE_ACCESSORS(UTalents, Grit)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData GritMax;
	ATTRIBUTE_ACCESSORS(UTalents, GritMax)
	
};

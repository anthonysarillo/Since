#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "PrimarySet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class SINCE_API UPrimarySet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// Constructor
	UPrimarySet();
	
	// Overrides
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// HUMAN - Primary Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HumanPoints;
	ATTRIBUTE_ACCESSORS(UPrimarySet, HumanPoints)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HumanPointsMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, HumanPointsMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UPrimarySet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HealthMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, HealthMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Utility;
	ATTRIBUTE_ACCESSORS(UPrimarySet, Utility)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData UtilityMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, UtilityMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Muscle;
	ATTRIBUTE_ACCESSORS(UPrimarySet, Muscle)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MuscleMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, MuscleMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Acumen;
	ATTRIBUTE_ACCESSORS(UPrimarySet, Acumen)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AcumenMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, AcumenMax)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Nerve;
	ATTRIBUTE_ACCESSORS(UPrimarySet, Nerve)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData NerveMax;
	ATTRIBUTE_ACCESSORS(UPrimarySet, NerveMax)


	
};

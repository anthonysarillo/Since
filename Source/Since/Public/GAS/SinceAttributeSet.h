// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "SinceAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class SINCE_API USinceAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	USinceAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	// Primary Attributes

	// Derived Attributes
	UPROPERTY(BlueprintReadOnly, Category="Since|Attributes|Derived", ReplicatedUsing=OnRep_HitPoints)
	FGameplayAttributeData HitPoints;
	ATTRIBUTE_ACCESSORS(ThisClass,HitPoints)

	UPROPERTY(BlueprintReadOnly, Category="Since|Attributes|Derived", ReplicatedUsing=OnRep_HitPointsMax)
	FGameplayAttributeData HitPointsMax;
	ATTRIBUTE_ACCESSORS(ThisClass,HitPointsMax)

	UPROPERTY(BlueprintReadOnly, Category="Since|Attributes|Derived", ReplicatedUsing=OnRep_Energy)
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(ThisClass,Energy)

	UPROPERTY(BlueprintReadOnly, Category="Since|Attributes|Derived", ReplicatedUsing=OnRep_EnergyMax)
	FGameplayAttributeData EnergyMax;
	ATTRIBUTE_ACCESSORS(ThisClass,EnergyMax)

	// Talent Attributes

	// Bonus Attributes

protected:
	// Primary RepNotifies
	
	// Derived RepNotifies
	UFUNCTION()
	virtual void OnRep_HitPoints(const FGameplayAttributeData& OldHitPoints);

	UFUNCTION()
	virtual void OnRep_HitPointsMax(const FGameplayAttributeData& OldHitPointsMax);

	UFUNCTION()
	virtual void OnRep_Energy(const FGameplayAttributeData& OldEnergy);

	UFUNCTION()
	virtual void OnRep_EnergyMax(const FGameplayAttributeData& OldEnergyMax);

	// Talent RepNotifies

	// Bonus RepNotifies
	
};



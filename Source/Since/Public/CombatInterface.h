#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

class ACritter;

UENUM(BlueprintType)
enum class ECombatantType : uint8
{
	Enemy UMETA(DisplayName = "Enemy"),
	Creature UMETA(DisplayName = "Creature")
};

USTRUCT(BlueprintType)
struct FCombatantData
{
	GENERATED_BODY()

	FCombatantData() :

	CombatantType(ECombatantType::Enemy),
	Name(FText::GetEmpty()),
	CombatDuration(0.0f)
	{};

	UPROPERTY(EditInstanceOnly)
	ECombatantType CombatantType;

	UPROPERTY(EditInstanceOnly)
	FText Name;

	UPROPERTY(EditInstanceOnly)
	float CombatDuration;
	
};

UINTERFACE(MinimalAPI)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};
class SINCE_API ICombatInterface
{
	GENERATED_BODY()

public:
	FCombatantData CombatantData;

	virtual void BeginTargeting();
	virtual void EndTargeting();
	virtual void BeginCombat();
	virtual void EndCombat();
	virtual void Combat(ACritter* InstigatorCharacter);
};

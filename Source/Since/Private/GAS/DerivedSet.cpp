// GAME
#include "GAS/DerivedSet.h"

// ENGINE
#include "GameplayEffectExtension.h"

UDerivedSet::UDerivedSet()
{
	// Derived
	InitDudeLevel(1);
	InitDudeLevelMax(30);
	InitXP(0);
	InitXPMax(200);
	InitHitPoints(120);
	InitHitPointsMax(120);
	InitHitPointsRegenRate(1);
	InitEnergy(70);
	InitEnergyMax(70);
	InitEnergyRegenRate(1);
	InitBackpack(160);
	InitBackpackMax(160);
	InitCrit(.01); 
	InitCritMax(.01);
	InitResistance(0);
	InitThreshold(0);
	InitDamage(0);
	InitUnarmedDamage(.5);
	InitMeleeDamage(.5);
	InitReloadSpeed(1);
	InitMoveSpeed(1);
	InitTalentPoints(10);
	InitTalentPointsMax(20);
	InitThirst(0);
	InitThirstMax(1000);
	InitExhaustion(0);
	InitExhaustionMax(1000);
	InitHunger(0);
	InitHungerMax(1000);
}

void UDerivedSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetDudeLevelAttribute())
	{
		const float DudeLevelDelta = Data.EvaluatedData.Magnitude;
		SetDudeLevel(FMath::Clamp(GetDudeLevel(), 1, GetDudeLevelMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetHitPointsAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetHitPoints(FMath::Clamp(GetHitPoints(), 0, GetHitPointsMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetEnergyAttribute())
	{
		const float EnergyDelta = Data.EvaluatedData.Magnitude;
		SetEnergy(FMath::Clamp(GetEnergy(), 0, GetEnergyMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetBackpackAttribute())
	{
		const float BackpackDelta = Data.EvaluatedData.Magnitude;
		SetBackpack(FMath::Clamp(GetBackpack(), 160, GetBackpackMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetCritAttribute())
	{
		const float CritDelta = Data.EvaluatedData.Magnitude;
		SetCrit(FMath::Clamp(GetCrit(), .01, GetCritMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetTalentPointsAttribute())
	{
		const float TalentPointsDelta = Data.EvaluatedData.Magnitude;
		SetTalentPoints(FMath::Clamp(GetTalentPoints(), 10, GetTalentPointsMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetThirstAttribute())
	{
		const float ThirstDelta = Data.EvaluatedData.Magnitude;
		SetThirst(FMath::Clamp(GetThirst(), 0, GetThirstMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetExhaustionAttribute())
	{
		const float ExhaustionDelta = Data.EvaluatedData.Magnitude;
		SetExhaustion(FMath::Clamp(GetExhaustion(), 0, GetExhaustionMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetHungerAttribute())
	{
		const float HungerDelta = Data.EvaluatedData.Magnitude;
		SetHunger(FMath::Clamp(GetHunger(), 0, GetHungerMax()));
	}
}

// GAME
#include "GAS/Talents.h"

// ENGINE
#include "GameplayEffectExtension.h"

UTalents::UTalents()
{
	InitFisticuffs(0);
	InitFisticuffsMax(100);
	InitCloseQuarters(0);
	InitCloseQuartersMax(100);
	InitFirearms(0);
	InitFirearmsMax(100);
	InitStealth(0);
	InitStealthMax(100);
	InitHaggle(0);
	InitHaggleMax(100);
	InitGab(0);
	InitGabMax(100);
	InitRemedy(0);
	InitRemedyMax(100);
	InitBeeNee(0);
	InitBeeNeeMax(100);
	InitRestore(0);
	InitRestoreMax(100);
	InitGrit(0);
	InitGritMax(100);
}

void UTalents::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetFisticuffsAttribute())
	{
		const float DudeLevelDelta = Data.EvaluatedData.Magnitude;
		SetFisticuffs(FMath::Clamp(GetFisticuffs(), 0, GetFisticuffsMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetCloseQuartersAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetCloseQuarters(FMath::Clamp(GetCloseQuarters(), 0, GetCloseQuartersMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetFirearmsAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetFirearms(FMath::Clamp(GetFirearms(), 0, GetFirearmsMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetStealthAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetStealth(FMath::Clamp(GetStealth(), 0, GetStealthMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetHaggleAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetHaggle(FMath::Clamp(GetHaggle(), 0, GetHaggleMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetGabAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetGab(FMath::Clamp(GetGab(), 0, GetGabMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetRemedyAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetRemedy(FMath::Clamp(GetRemedy(), 0, GetRemedyMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetBeeNeeAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetBeeNee(FMath::Clamp(GetBeeNee(), 0, GetBeeNeeMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetRestoreAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetRestore(FMath::Clamp(GetRestore(), 0, GetRestoreMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetGritAttribute())
	{
		const float HitPointsDelta = Data.EvaluatedData.Magnitude;
		SetGrit(FMath::Clamp(GetGrit(), 0, GetGritMax()));
	}
}

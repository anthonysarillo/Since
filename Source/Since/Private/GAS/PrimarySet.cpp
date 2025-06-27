// GAME
#include "GAS/PrimarySet.h"

// ENGINE
#include "GameplayEffectExtension.h"

UPrimarySet::UPrimarySet()
{
	InitHumanPoints(25);
	InitHumanPointsMax(25);
	InitHealth(1);
	InitHealthMax(10);
	InitUtility(1);
	InitUtilityMax(10);
	InitMuscle(1);
	InitMuscleMax(10);
	InitAcumen(1);
	InitAcumenMax(10);
	InitNerve(1);
	InitNerveMax(10);
}

void UPrimarySet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHumanPointsAttribute())
	{
		const float HumanPointsDelta = Data.EvaluatedData.Magnitude;
		SetHumanPoints(FMath::Clamp(GetHumanPoints(), 0, GetHumanPointsMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		const float HealthDelta = Data.EvaluatedData.Magnitude;
		SetHealth(FMath::Clamp(GetHealth(), 1, GetHealthMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetUtilityAttribute())
	{
		const float UtilityDelta = Data.EvaluatedData.Magnitude;
		SetUtility(FMath::Clamp(GetUtility(), 1, GetUtilityMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetMuscleAttribute())
	{
		const float MuscleDelta = Data.EvaluatedData.Magnitude;
		SetMuscle(FMath::Clamp(GetMuscle(), 1, GetMuscleMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetAcumenAttribute())
	{
		const float AcumenDelta = Data.EvaluatedData.Magnitude;
		SetAcumen(FMath::Clamp(GetAcumen(), 1, GetAcumenMax()));
	}
	else if (Data.EvaluatedData.Attribute == GetNerveAttribute())
	{
		const float NerveDelta = Data.EvaluatedData.Magnitude;
		SetNerve(FMath::Clamp(GetNerve(), 1, GetNerveMax()));
	}
}

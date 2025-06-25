// GAME
#include "GAS/DerivedSet.h"

UDerivedSet::UDerivedSet()
{
	// Derived
	DudeLevel = 1;
	DudeLevelMax = 30;
	XP = 0;
	XPMax = 200;
	HitPoints = 120;
	HitPointsMax = 120;
	HitPointsRegenRate = 1;
	Energy = 68;
	EnergyMax = 68;
	EnergyRegenRate = 1;
	Backpack = 160;
	BackpackMax = 160;
	Crit = .01; 
	CritMax = .01;
	Resistance =0;
	Threshold = 0;
	Damage = 0;
	UnarmedDamage = .75;
	MeleeDamage = .5;
	ReloadSpeed = 1.5;
	MoveSpeed = 1;
	TalentPoints = 10;
	TalentPointsMax = 20;
	Thirst = 0;
	ThirstMax = 1000;
	Exhaustion = 0;
	ExhaustionMax = 1000;
	Hunger = 0;
	HungerMax = 1000;
}

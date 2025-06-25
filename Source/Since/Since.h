#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ESinceAbilityInputID : uint8
{
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel"),
	Contact UMETA(DisplayName = "Contact"), // Interact
	Block UMETA(DisplayName = "Block"),
	Aim UMETA(DisplayName = "Aim"),
	Attack UMETA(DisplayName = "Attack"),
	Ready UMETA(DisplayName = "Ready"),
	Reload UMETA(DisplayName = "Reload"),
	Sneak UMETA(DisplayName = "Sneak"),
	Jump UMETA(DisplayName = "Jump"),
	Cache UMETA(DisplayName = "Cache"),
	Pause UMETA(DisplayName = "Pause"),
	Light UMETA(DisplayName = "Light"),
	
};


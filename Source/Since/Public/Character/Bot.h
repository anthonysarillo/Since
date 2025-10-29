// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "SinceCharacter.h"
#include "Bot.generated.h"

UCLASS()
class SINCE_API ABot : public ASinceCharacter
{
	GENERATED_BODY()

public:
	ABot();

protected:
	virtual void BeginPlay() override;

};



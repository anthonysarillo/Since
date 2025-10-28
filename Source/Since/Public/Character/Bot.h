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
	// Sets default values for this character's properties
	ABot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

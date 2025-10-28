// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "SinceCharacter.h"
#include "Dude.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SINCE_API ADude : public ASinceCharacter
{
	GENERATED_BODY()

public:
	ADude();

	USpringArmComponent* GetSpringArm() const { return SpringArm; }
	UCameraComponent* GetThirdPersonCamera() const { return ThirdPersonCamera; }
	UCameraComponent* GetFirstPersonCamera() const { return FirstPersonCamera; }

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Since|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Since|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Since|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;
	
};

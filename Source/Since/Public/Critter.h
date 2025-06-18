#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Critter.generated.h"

class ACritterController;
class ASinceHUD;
class ICombatInterface;
class IInteractionInterface;
class UCameraComponent;
class USpringArmComponent;
class UCritterConfig;

// INTERACTION DATA
USTRUCT(BlueprintType)
struct FInteractionData
{
	GENERATED_BODY()

	FInteractionData() :

	CurrentInteractable(nullptr),
	LastInteractionCheckTime(0.0f)
	{};

	UPROPERTY()
	TObjectPtr<AActor> CurrentInteractable;

	UPROPERTY()
	float LastInteractionCheckTime;
	
};

// COMBAT DATA
USTRUCT(BlueprintType)
struct FCombatData
{
	GENERATED_BODY()

	FCombatData() :

	CurrentCombatant(nullptr),
	LastCombatCheckTime(0.0f)
	{};

	UPROPERTY()
	TObjectPtr<AActor> CurrentCombatant;

	UPROPERTY()
	float LastCombatCheckTime;
	
};

UCLASS()
class SINCE_API ACritter : public ACharacter
{
	GENERATED_BODY()

public:
	// CONSTRUCTOR
	ACritter();
	
	// OVERRIDES
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	virtual FVector GetPawnViewLocation() const override;

	// INTERACTION
	FORCEINLINE bool IsInteracting() const { return GetWorldTimerManager().IsTimerActive(TimerHandle_Interaction); };
	void UpdateInteractionWidget() const;

	// COMBAT
	FORCEINLINE bool IsInCombat() const { return GetWorldTimerManager().IsTimerActive(TimerHandle_Combat); };
	void UpdateCombatWidget() const;

protected:
	// BEGIN PLAY
	virtual void BeginPlay() override;

	// HUD
	UPROPERTY()
	TObjectPtr<ASinceHUD> HUD;

	// PLAYER CONTROLLER
	UPROPERTY()
	TObjectPtr<ACritterController> CritterController;

	// CRITTER CONFIG
	UPROPERTY(EditDefaultsOnly, Category="Config")
	TObjectPtr<UCritterConfig> CritterConfig;

	// SPRING ARM
	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	// THIRD PERSON CAMERA
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	// ENHANCED INPUT
	void Move(const FInputActionInstance& Instance);
	void Look(const FInputActionValue& InputValue);
	void Activate();
	void Attack();

	// INTERACTION
	UPROPERTY(VisibleAnywhere, Category="Interaction")
	TScriptInterface<IInteractionInterface> TargetInteractable;
	
	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionCheckFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionCheckDistance;

	UPROPERTY(EditDefaultsOnly,Category="Interaction")
	float LookDirection;

	FTimerHandle TimerHandle_Interaction;
	FInteractionData InteractionData;

	void PerformInteractionCheck();
	void FoundInteractable(AActor* NewInteractable);
	void NoInteractableFound();
	void BeginInteract();
	void EndInteract();

	// COMBAT
	UPROPERTY(VisibleAnywhere, Category="Combat")
	TScriptInterface<ICombatInterface> TargetCombatant;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	float CombatCheckFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	float CombatCheckDistance;

	UPROPERTY(EditDefaultsOnly,Category="Combat")
	float TargetDirection;

	FTimerHandle TimerHandle_Combat;
	FCombatData CombatData;

	virtual void PerformCombatCheck();
	virtual void FoundCombatant(AActor* NewCombatant);
	virtual void NoCombatantFound();
	virtual void BeginCombat();
	virtual void EndCombat();
	
};

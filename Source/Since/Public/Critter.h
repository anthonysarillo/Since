#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Critter.generated.h"

class UCrosshairBracketsWidget;
class UCrosshairWidget;
class USpotLightComponent;
class ACritterController;
class ASinceHUD;
class ICombatInterface;
class IInteractionInterface;
class UCameraComponent;
class USpringArmComponent;
class UCritterConfig;

// CRITTER OVERLAY STATES - ANIMATION
UENUM(Blueprintable)
enum class ECritterOverlayStates : uint8
{
	Unarmed UMETA(DisplayName = "Unarmed"),
	Ready UMETA(DisplayName = "Ready"),
	MeleeOneHand UMETA(DisplayName = "MeleeOneHand"),
	MeleeTwoHand UMETA(DisplayName = "MeleeTwoHand"),
	Pistol UMETA(DisplayName = "Pistol"),
	Rifle UMETA(DisplayName = "Rifle"),
	Shotgun UMETA(DisplayName = "Shotgun")
};

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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	TObjectPtr<ASinceHUD> HUD;

	// PLAYER CONTROLLER
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Critter Controller")
	TObjectPtr<ACritterController> CritterController;

	// CRITTER CONFIG
	UPROPERTY(EditDefaultsOnly, Category="Config")
	TObjectPtr<UCritterConfig> CritterConfig;

	// SPRING ARM
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	// THIRD PERSON CAMERA
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	TObjectPtr<UCameraComponent> ThirdPersonCameraRef;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	FVector ThirdPersonCameraLocation;

	// FIRST PERSON CAMERA
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	FVector FirstPersonCameraLocation;

	// CHEST LIGHT COMPONENT
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	TObjectPtr<USpotLightComponent> ChestLightComp;

	// CRITTER OVERLAY STATES - ANIMATION
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Animation")
	ECritterOverlayStates CritterOverlayState;

	// ENHANCED INPUT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Sneaking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Jumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool ThirdPersonView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool ChestLightOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Interacting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Aiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Attacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool bReady;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool MeleeOneHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool MeleeTwoHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Pistol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Rifle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input | Properties")
	bool Shotgun;
	
	void Move(const FInputActionInstance& Instance);
	void Look(const FInputActionValue& InputValue);
	void Sneak();
	void ChangeView();
	void ChestLight();
	void Activate();
	void Ready();
	void Aim();
	void StopAim();
	void Attack();

	// INTERACTION
	UPROPERTY(VisibleAnywhere, Category="Interaction")
	TScriptInterface<IInteractionInterface> TargetInteractable;
	
	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionCheckFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionCheckDistance;

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

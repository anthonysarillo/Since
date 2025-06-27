#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "AbilitySystemInterface.h"
#include "Dude.generated.h"

class UQualities;
class UBonuses;
class UTalents;
class UCameraComponent;
class USpringArmComponent;
class UDudeInputConfig;
class USinceGameplayAbility;
class UWeaponSet;
class UDerivedSet;
class UPrimarySet;
class USinceAbilitySystemComponent;


UCLASS()
class SINCE_API ADude : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Constructor
	ADude();

	// Overrides
	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float DeltaTime) override;
	virtual FVector GetPawnViewLocation() const override;

	// Implement IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Implement AttributeSets
	UFUNCTION(BlueprintPure)
	const UPrimarySet* GetPrimarySet();
	UFUNCTION(BlueprintPure)
	const UDerivedSet* GetDerivedSet();
	UFUNCTION(BlueprintPure)
	const UTalents* GetTalents();
	UFUNCTION(BlueprintPure)
	const UBonuses* GetBonuses();
	UFUNCTION(BlueprintPure)
	const UQualities* GetQualities();
	UFUNCTION(BlueprintPure)
	const UWeaponSet* GetWeaponSet();

	// Abilities
	virtual void GiveAbilities();

protected:
	// Begin Play
	virtual void BeginPlay() override;

	// SinceAbilitySystemComponent
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<USinceAbilitySystemComponent> SinceAbilitySystemComponent;

	// AttributeSets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UPrimarySet> PrimarySet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UDerivedSet> DerivedSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UTalents> Talents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UBonuses> Bonuses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UQualities> Qualities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "GAS")
	TObjectPtr<const UWeaponSet> WeaponSet;

	// Abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "GAS")
	TArray<TSubclassOf<USinceGameplayAbility>> DudeAbilities;

	// DudeInputConfig
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Config")
	TObjectPtr<UDudeInputConfig> DudeInputConfig;

	// Enhanced Input
	void Move(const FInputActionInstance& Instance);
	void Look(const FInputActionValue& InputValue);
	void Contact();
	void Block();
	void BlockStop();
	void Aim();
	void AimStop();
	void Attack();
	void AttackStop();
	void Ready();
	void Reload();
	void Sneak();
	void Cache();
	void Pause();
	void Light();
	
	// SpringArm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	// ThirdPersonCamera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;
	




};

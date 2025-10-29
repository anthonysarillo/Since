// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SincePlayerController.generated.h"

class UAbilitySystemComponent;
class UInventoryComponent;
class UHeadsUpDisplay;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class SINCE_API ASincePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASincePlayerController();
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Since|Input")
	void Activate();

	UFUNCTION(BlueprintCallable, Category = "Since|Input")
	void ToggleInventory();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Since|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> SinceContext;

	/** Move */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Since|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> Input_Move;

	/** Look */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Since|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> Input_Look;

	/** Activate */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Since|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> Input_Activate;

	/** Activate */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Since|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> Input_Inventory;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	/** HeadsUpDisplay */
	void CreateHeadsUpDisplay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	UPROPERTY()
	TObjectPtr<UHeadsUpDisplay> HeadsUpDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Since|UI")
	TSubclassOf<UHeadsUpDisplay> HeadsUpDisplayClass;

	/** Contact */
	void ContactTrace();

	UPROPERTY(EditDefaultsOnly, Category = "Since|Contact")
	double ContactTraceLength;
	
	TWeakObjectPtr<AActor> ThisContact;
	TWeakObjectPtr<AActor> LastContact;

	/** InventoryComponent */
	TWeakObjectPtr<UInventoryComponent> InventoryComponent;
};

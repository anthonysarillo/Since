// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "SinceFastArray.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemComponent;
class UInventoryItem;
class UInventoryBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UInventoryItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMaxBackpack);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class SINCE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Since|Inventory")
	void TryAddItem(UItemComponent* ItemComponent);

	UFUNCTION(Server, Reliable)
	void Server_AddNewItem(UItemComponent* ItemComponent, int32 StackCount);
	UFUNCTION(Server, Reliable)
	void Server_AddStacksToItem(UItemComponent* ItemComponent, int32 StackCount, int32 Remainder);

	void ToggleInventoryMenu();

	void AddRepSubObj(UObject* SubObj);

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;
	FMaxBackpack OnMaxBackpack;

protected:
	virtual void BeginPlay() override;

private:
	void ConstructInventory();

	UPROPERTY(Replicated)
	FInventoryFastArray InventoryList;

	TWeakObjectPtr<APlayerController> OwningController;

	UPROPERTY()
	TObjectPtr<UInventoryBase> InventoryMenu;

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	TSubclassOf<UInventoryBase> InventoryMenuClass;

	bool bInventoryMenuOpen {false};
	void OpenInventoryMenu();
	void CloseInventoryMenu();
	
	
};



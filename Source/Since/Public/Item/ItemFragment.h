// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemFragment.generated.h"

/**
 * 
 */

class UButton;

USTRUCT(BlueprintType)
struct FItemFragment
{
	GENERATED_BODY()

	FItemFragment() {}
	FItemFragment(const FItemFragment&) = default;
	FItemFragment& operator=(const FItemFragment&) = default;
	FItemFragment(FItemFragment&&) = default;
	FItemFragment& operator=(FItemFragment&&) = default;
	virtual ~FItemFragment() {}

	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(FGameplayTag Tag) { FragmentTag = Tag; }

private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};

USTRUCT(BlueprintType)
struct FGridFragment : public FItemFragment
{
	GENERATED_BODY()

	FIntPoint GetGridSize() const { return GridSize; }
	void SetGridSize(FIntPoint Size) { GridSize = Size; }

	FMargin GetGridPadding() const { return GridPadding; }
	void SetGridPadding(FMargin Padding) { GridPadding = Padding; }
	
private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	FIntPoint GridSize {1,1};

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	FMargin GridPadding {0,0,0,0};
};

USTRUCT(BlueprintType)
struct FWidgetFragment : public FItemFragment
{
	GENERATED_BODY()

	UUserWidget* GetItemWidget() const { return ItemWidget; }
	void SetItemWidget(UUserWidget* UserWidget) { ItemWidget = UserWidget; }

	FMargin GetWidgetPadding() const { return WidgetPadding; }
	void SetWidgetPadding(FMargin Padding) { WidgetPadding = Padding; }

private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	TObjectPtr<UUserWidget> ItemWidget;

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	FMargin WidgetPadding {0,0,0,0};
};

USTRUCT(BlueprintType)
struct FStackableFragment : public FItemFragment
{
	GENERATED_BODY()

	int32 GetMaxStackSize() const { return MaxStackSize; }
	int32 GetStackCount() const { return StackCount; }

private:
	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 MaxStackSize {1};

	UPROPERTY(EditAnywhere, Category="Since|Inventory")
	int32 StackCount {1};
};



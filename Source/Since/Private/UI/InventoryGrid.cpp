// Since - 2025


#include "UI/InventoryGrid.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ScrollBox.h"
#include "Components/ScrollBoxSlot.h"
#include "Statics/WidgetStatics.h"
#include "UI/InventoryGridSlot.h"

void UInventoryGrid::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ConstructInventoryGrid();
}

void UInventoryGrid::ConstructInventoryGrid()
{
	InventoryGridSlots.Reserve(Rows * Columns);

	for (int32 j = 0; j < Rows; ++j)
	{
		for (int32 i = 0; i < Columns; ++i)
		{
			UInventoryGridSlot* GridSlot = CreateWidget<UInventoryGridSlot>(this, InventoryGridSlotClass);
			//InventoryGridCanvasPanel->AddChild(GridSlot);
			InventoryGridScrollBox->AddChild(GridSlot);

			const FIntPoint TilePosition(i, j);
			GridSlot->SetTileIndex(UWidgetStatics::GetIndexFromPosition(FIntPoint(i, j), Columns));

			UScrollBoxSlot* ScrollBoxSlot = UWidgetLayoutLibrary::SlotAsScrollBoxSlot(GridSlot);
			ScrollBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
			ScrollBoxSlot->SetPadding(FMargin(5, 5, 5, 5));
			ScrollBoxSlot->SetHorizontalAlignment(HAlign_Fill);
			ScrollBoxSlot->SetVerticalAlignment(VAlign_Top);

			//UCanvasPanelSlot* CanvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(GridSlot);
			//CanvasSlot->SetSize(FVector2D(TileSize));
			//CanvasSlot->SetPosition(TilePosition * TileSize);

			InventoryGridSlots.Add(GridSlot);
		}
	}
}

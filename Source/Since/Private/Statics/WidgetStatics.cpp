// Since - 2025


#include "Statics/WidgetStatics.h"

int32 UWidgetStatics::GetIndexFromPosition(const FIntPoint& Position, const int32 Columns)
{
	return Position.X + Position.Y * Columns;
}

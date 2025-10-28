// Since - 2025


#include "UI/MaxBackpackMessage.h"
#include "Components/TextBlock.h"

void UMaxBackpackMessage::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MaxBackpackMessage->SetText(FText::GetEmpty());
	HideMaxBackpackMessage();
}

void UMaxBackpackMessage::SetMaxBackpackMessage(const FText& Message)
{
	MaxBackpackMessage->SetText(Message);

	if (!bIsMaxBackpackMessageActive)
	{
		ShowMaxBackpackMessage();
	}
	bIsMaxBackpackMessageActive = true;

	GetWorld()->GetTimerManager().SetTimer(MaxBackpackMessageTimer, [this] ()
	{
		HideMaxBackpackMessage();
		bIsMaxBackpackMessageActive = false;
	}, MaxBackpackMessageLifetime, false);
}

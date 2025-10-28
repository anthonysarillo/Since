// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContactComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class SINCE_API UContactComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UContactComponent();

	FText GetContactMessage() const { return ContactMessage; }
	FText GetContactName() const { return ContactName; }

private:
	UPROPERTY(EditAnywhere, Category="Since|Contact")
	FText ContactMessage;

	UPROPERTY(EditAnywhere, Category="Since|Contact")
	FText ContactName;
	
	
};

﻿// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SinceEffectActor.generated.h"

class UHighlightableStaticMesh;
class USphereComponent;

UCLASS()
class SINCE_API ASinceEffectActor : public AActor
{
	GENERATED_BODY()

public:
	ASinceEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHighlightableStaticMesh> Mesh;


};

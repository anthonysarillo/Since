// Since - 2025

#pragma once

#include "CoreMinimal.h"
#include "Highlightable.h"
#include "Components/StaticMeshComponent.h"
#include "HighlightableStaticMesh.generated.h"

/**
 * 
 */
UCLASS()
class SINCE_API UHighlightableStaticMesh : public UStaticMeshComponent, public IHighlightable
{
	GENERATED_BODY()

public:
	virtual void Highlight_Implementation() override;
	virtual void UnHighlight_Implementation() override;

private:
	UPROPERTY(EditAnywhere, Category="Since|Contact")
	TObjectPtr<UMaterialInterface> HighlightMaterial;
};

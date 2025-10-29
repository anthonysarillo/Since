// Since - 2025


#include "Effect/SinceEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "GAS/SinceAttributeSet.h"
#include "Interaction/HighlightableStaticMesh.h"


ASinceEffectActor::ASinceEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UHighlightableStaticMesh>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ASinceEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

void ASinceEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// remove const_cast
	if (IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USinceAttributeSet* SinceAttributeSet = Cast<USinceAttributeSet>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(USinceAttributeSet::StaticClass()));
		USinceAttributeSet* MutableSinceAttributeSet = const_cast<USinceAttributeSet*>(SinceAttributeSet);
		MutableSinceAttributeSet->SetHitPoints(SinceAttributeSet->GetHitPoints() + 25.f);
		Destroy();
	}
}

void ASinceEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}




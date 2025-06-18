// GAME
#include "CombatTestActor.h"
#include "Since/Since.h"

// ENGINE

ACombatTestActor::ACombatTestActor()
{
 	PrimaryActorTick.bCanEverTick = true;

	Skeleton = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Skeleton;

}

void ACombatTestActor::BeginPlay()
{
	Super::BeginPlay();

	CombatantData = InstancedCombatantData;
	
}

void ACombatTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACombatTestActor::BeginTargeting()
{
	UE_LOG(LogSince, Display, TEXT("ACombatTestActor::BeginTargeting"));
}

void ACombatTestActor::EndTargeting()
{
	UE_LOG(LogSince, Display, TEXT("ACombatTestActor::EndTargeting"));
}

void ACombatTestActor::BeginCombat()
{
	UE_LOG(LogSince, Display, TEXT("ACombatTestActor::BeginCombat"));
}

void ACombatTestActor::EndCombat()
{
	UE_LOG(LogSince, Display, TEXT("ACombatTestActor::EndCombat"));
}

void ACombatTestActor::Combat(ACritter* InstigatorCharacter)
{
	UE_LOG(LogSince, Display, TEXT("ACombatTestActor::Combat"));

	Destroy();
}


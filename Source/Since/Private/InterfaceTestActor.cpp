// GAME
#include "InterfaceTestActor.h"
#include "Since/Since.h"

// ENGINE

AInterfaceTestActor::AInterfaceTestActor()
{
 	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

void AInterfaceTestActor::BeginPlay()
{
	Super::BeginPlay();

	InteractableData = InstanceInteractableData;
	
}

void AInterfaceTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInterfaceTestActor::BeginFocus()
{
	UE_LOG(LogSince, Display, TEXT("AInterfaceTestActor::BeginFocus"));
}

void AInterfaceTestActor::EndFocus()
{
	UE_LOG(LogSince, Display, TEXT("AInterfaceTestActor::EndFocus"));
}

void AInterfaceTestActor::BeginInteract()
{
	UE_LOG(LogSince, Display, TEXT("AInterfaceTestActor::BeginInteract"));

}

void AInterfaceTestActor::EndInteract()
{
	UE_LOG(LogSince, Display, TEXT("AInterfaceTestActor::EndInteract"));

}

void AInterfaceTestActor::Interact(ACritter* InstigatorCharacter)
{
	UE_LOG(LogSince, Display, TEXT("AInterfaceTestActor::Interact"));

	Destroy();
}



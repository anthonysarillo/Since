// GAME
#include "Pickup.h"

// ENGINE

APickup::APickup()
{
 	PrimaryActorTick.bCanEverTick = true;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	PickupMesh->SetSimulatePhysics(true);
	RootComponent = PickupMesh;
	
}

void APickup::BeginPlay()
{
	Super::BeginPlay();

	InteractableData = InstanceInteractableData;
	
}

void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup::BeginFocus()
{
	IInteractionInterface::BeginFocus();
}

void APickup::EndFocus()
{
	IInteractionInterface::EndFocus();
}

void APickup::BeginInteract()
{
	IInteractionInterface::BeginInteract();
}

void APickup::EndInteract()
{
	IInteractionInterface::EndInteract();
}

void APickup::Interact(ACritter* InstigatorCharacter)
{
	IInteractionInterface::Interact(InstigatorCharacter);

	Destroy();
}


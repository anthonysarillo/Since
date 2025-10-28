// Since - 2025


#include "Since/Public/Character/SinceCharacter.h"
#include "Components/CapsuleComponent.h"


ASinceCharacter::ASinceCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}




// Since - 2025


#include "Since/Public/Character/Dude.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Core/SincePlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


ADude::ADude()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0, 360.f, 0);
	GetCharacterMovement()->MaxWalkSpeed = 480.f;
	GetCharacterMovement()->JumpZVelocity = 480.f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 200.0f; 
	SpringArm->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); 
	ThirdPersonCamera->bUsePawnControlRotation = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), FName("head")); 
	FirstPersonCamera->bUsePawnControlRotation = true; 
}

void ADude::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// InitAbilityActorInfo() for the Server
	InitAbilityActorInfo();
}

void ADude::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// InitAbilityActorInfo() for the client
	InitAbilityActorInfo();
}

void ADude::InitAbilityActorInfo()
{
	ASincePlayerState* SincePlayerState = GetPlayerState<ASincePlayerState>();
	check(SincePlayerState);
	SincePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SincePlayerState, this);
	AbilitySystemComponent = SincePlayerState->GetAbilitySystemComponent();
	AttributeSet = SincePlayerState->GetAttributeSet();
}




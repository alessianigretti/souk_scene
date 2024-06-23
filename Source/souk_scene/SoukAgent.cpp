// Project Souk - 2024


#include "SoukAgent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/FiniteStateMachineComponent.h"

ASoukAgent::ASoukAgent()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<USoukAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AddInstanceComponent(AbilitySystemComponent);
	AbilitySystemComponent->bEditableWhenInherited = true;

	AttributeSetBase = CreateDefaultSubobject<USoukAttributeSetBase>(TEXT("AttributeSetBase"));

	NetUpdateFrequency = 100;
}

void ASoukAgent::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AActor* OwnerActor = Cast<AActor>(NewController->GetCharacter()))
	{
		AbilitySystemComponent->InitAbilityActorInfo(OwnerActor, this);
	}
}

UAbilitySystemComponent* ASoukAgent::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

USoukAttributeSetBase* ASoukAgent::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

void ASoukAgent::BeginPlay()
{
	Super::BeginPlay();

	if (UCharacterMovementComponent* MovementComp = GetComponentByClass<UCharacterMovementComponent>())
	{
		MovementComp->bUseControllerDesiredRotation = true;
		MovementComp->bOrientRotationToMovement = true;
		MovementComp->UseAccelerationForPathFollowing();
	}
}

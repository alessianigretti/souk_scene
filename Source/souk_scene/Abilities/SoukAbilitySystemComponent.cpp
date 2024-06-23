// Project Sparrow - 2024.


#include "SoukAbilitySystemComponent.h"

void USoukAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UFiniteStateMachineTaskBase> Ability : StartupAbilities)
	{
		GiveAbility(FGameplayAbilitySpec(Ability.Get()));
	}
}

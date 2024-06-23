// Project Souk - 2024.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "souk_scene/SoukAgent.h"
#include "SoukGameplayAbility.generated.h"

UCLASS()
class SOUK_SCENE_API USoukGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

public:

	UPROPERTY(BlueprintReadOnly)
	ASoukAgent* Agent;
};

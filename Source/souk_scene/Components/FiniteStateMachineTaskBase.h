// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FiniteStateMachineTaskBase.generated.h"

class UFiniteStateMachineConditionBase;

/**
 * 
 */
UCLASS(Blueprintable)
class SOUK_SCENE_API UFiniteStateMachineTaskBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UFiniteStateMachineTaskBase();

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};

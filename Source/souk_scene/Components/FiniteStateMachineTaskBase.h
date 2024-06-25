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

	UFUNCTION(BlueprintCallable)
	void InjectTarget(APawn* Target);

	UPROPERTY(BlueprintReadOnly)
	APawn* Pawn;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bCanBeInterrupted;

	UPROPERTY(BlueprintReadOnly)
	bool bHasEnded;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStateInjectedDelegate);
	UPROPERTY(BlueprintAssignable)
	FOnStateInjectedDelegate OnStateInjected;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};

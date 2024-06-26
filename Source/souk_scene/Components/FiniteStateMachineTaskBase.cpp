// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineTaskBase.h"
#include "FiniteStateMachineComponent.h"

UFiniteStateMachineTaskBase::UFiniteStateMachineTaskBase()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

TSubclassOf<UFiniteStateMachineTaskBase> UFiniteStateMachineTaskBase::InjectTarget(APawn* Target)
{
	if (Target != nullptr)
	{
		UFiniteStateMachineComponent* FiniteStateMachineComponent = Target->GetComponentByClass<UFiniteStateMachineComponent>();
		FiniteStateMachineComponent->InjectIntoCurrentTask(GetClass());
		return FiniteStateMachineComponent->CurrentTask->GetClass();
	}

	return nullptr;
}

void UFiniteStateMachineTaskBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (GEngine)
	{
		FString Msg = ActorInfo->AvatarActor->GetName().Append(": ").Append(GetName());
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, Msg);
	}

	Pawn = Cast<APawn>(ActorInfo->AvatarActor);
	bHasEnded = false;

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UFiniteStateMachineTaskBase::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	bHasEnded = true;
}

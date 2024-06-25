// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineComponent.h"
#include "AbilitySystemComponent.h"
#include "FiniteStateMachineConditionBase.h"

UFiniteStateMachineComponent::UFiniteStateMachineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFiniteStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!CurrentTask)
	{
		return;
	}

	// Has not yet ended and also cannot be interrupted
	if (!CurrentTask->bCanBeInterrupted && !CurrentTask->bHasEnded)
	{
		return;
	}

	TArray<TSubclassOf<UFiniteStateMachineTaskBase>> LinkedTasks = Graph.Find(CurrentTask->GetClass())->LinkedTasks;

	for (int i = 0; i < LinkedTasks.Num(); i++)
	{
		FGameplayAbilitySpec* ActivatableSpec = AbilitySystemComponent->FindAbilitySpecFromClass(LinkedTasks[i]);
		if (ActivatableSpec->Ability->CanActivateAbility(ActivatableSpec->Handle, AbilitySystemComponent->AbilityActorInfo.Get())
			&& ActivatableSpec->Ability->GetClass() != CurrentTask->GetClass())
		{
			// Has not called OnEndAbility yet
			if (!CurrentTask->bHasEnded && !CurrentTask->IsActive())
			{
				FGameplayAbilitySpec* EndingAbilitySpec = AbilitySystemComponent->FindAbilitySpecFromClass(CurrentTask->GetClass());
				UFiniteStateMachineTaskBase* EndingTask = Cast<UFiniteStateMachineTaskBase>(EndingAbilitySpec->Ability.Get());
				EndingTask->EndAbility(EndingAbilitySpec->Handle, AbilitySystemComponent->AbilityActorInfo.Get(), EndingAbilitySpec->ActivationInfo, false, true);
			}

			// Has called OnEndAbility and we're waiting for it to complete
			if (CurrentTask->bHasEnded && AbilitySystemComponent->TryActivateAbilityByClass(LinkedTasks[i], false))
			{
				CurrentTask = Cast<UFiniteStateMachineTaskBase>(ActivatableSpec->GetPrimaryInstance());
				break;
			}
		}
	}
}

void UFiniteStateMachineComponent::InjectIntoCurrentTask()
{
	CurrentTask->OnStateInjected.Broadcast();
}

void UFiniteStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent = GetOwner()->GetComponentByClass<UAbilitySystemComponent>();

	if (AbilitySystemComponent)
	{
		if (AbilitySystemComponent->TryActivateAbilityByClass(StartTask, false))
		{
			FGameplayAbilitySpec* ActivatableSpec = AbilitySystemComponent->FindAbilitySpecFromClass(StartTask);
			CurrentTask = Cast<UFiniteStateMachineTaskBase>(ActivatableSpec->GetPrimaryInstance());
		}
	}
}


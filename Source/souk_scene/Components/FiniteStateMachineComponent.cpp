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

	if (!CurrentTask || CurrentTask->IsActive())
	{
		return;
	}

	TArray<TSubclassOf<UFiniteStateMachineTaskBase>> LinkedTasks = Graph.Find(CurrentTask->GetClass())->LinkedTasks;

	for (int i = 0; i < LinkedTasks.Num(); i++)
	{
		for (auto ActivatableAbility : AbilitySystemComponent->GetActivatableAbilities())
		{
			if (ActivatableAbility.Ability == LinkedTasks[i].GetDefaultObject())
			{
				if (ActivatableAbility.Ability->CanActivateAbility(ActivatableAbility.Handle, AbilitySystemComponent->AbilityActorInfo.Get())
					&& ActivatableAbility.Ability->GetClass() != CurrentTask->GetClass())
				{
					if (AbilitySystemComponent->TryActivateAbilityByClass(LinkedTasks[i], false))
					{
						CurrentTask = Cast<UFiniteStateMachineTaskBase>(ActivatableAbility.Ability);
						break;
					}
				}
			}
		}
		
	}
}

void UFiniteStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent = GetOwner()->GetComponentByClass<UAbilitySystemComponent>();

	if (AbilitySystemComponent)
	{
		if (AbilitySystemComponent->TryActivateAbilityByClass(StartTask, false))
		{
			for (auto ActivatableAbility : AbilitySystemComponent->GetActivatableAbilities())
			{
				if (ActivatableAbility.Ability == StartTask.GetDefaultObject())
				{
					CurrentTask = Cast<UFiniteStateMachineTaskBase>(ActivatableAbility.Ability);
					break;
				}
			}
		}
	}
}


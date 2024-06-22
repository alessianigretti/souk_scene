// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineComponent.h"
#include "FiniteStateMachineConditionBase.h"

UFiniteStateMachineComponent::UFiniteStateMachineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFiniteStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (int i = 0; i < CurrentTask->Conditions.Num(); i++)
	{
		UFiniteStateMachineConditionBase* ConditionPtr = Conditions.FindRef(CurrentTask->Conditions[i].Get());
		if (ConditionPtr->IsConditionMet())
		{
			CurrentTask->EndTask();
			CurrentTask = Tasks.FindRef(ConditionPtr->Task.Get());
			CurrentTask->RunLogic();
			break;
		}
	}
}

void UFiniteStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UFiniteStateMachineTaskBase> Task : AllowedTasks)
	{
		UFiniteStateMachineTaskBase* TaskPtr = NewObject<UFiniteStateMachineTaskBase>(this, Task.Get());
		Tasks.Add(Task.Get(), TaskPtr);
	}

	for (TSubclassOf<UFiniteStateMachineConditionBase> Condition : AllowedConditions)
	{
		UFiniteStateMachineConditionBase* ConditionPtr = NewObject<UFiniteStateMachineConditionBase>(this, Condition.Get());
		Conditions.Add(Condition.Get(), ConditionPtr);
	}

	CurrentTask = Tasks.FindRef(RootTask.Get());
	CurrentTask->RunLogic();
}


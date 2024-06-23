// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineTaskBase.h"

UFiniteStateMachineTaskBase::UFiniteStateMachineTaskBase()
{
	Owner = Cast<AActor>(GetOuter()->GetOuter());
}

void UFiniteStateMachineTaskBase::RunLogic_Implementation()
{
	bIsRunning = true;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, GetName());
	}
}

void UFiniteStateMachineTaskBase::EndTask_Implementation()
{
	bIsRunning = false;
}

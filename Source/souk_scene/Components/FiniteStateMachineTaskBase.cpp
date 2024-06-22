// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineTaskBase.h"

UFiniteStateMachineTaskBase::UFiniteStateMachineTaskBase()
{
	Owner = Cast<AActor>(GetOuter()->GetOuter());
}

void UFiniteStateMachineTaskBase::RunLogic_Implementation()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, GetName());
	}
}

void UFiniteStateMachineTaskBase::EndTask_Implementation()
{
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "FiniteStateMachineConditionBase.h"

UFiniteStateMachineConditionBase::UFiniteStateMachineConditionBase()
{
    Owner = Cast<AActor>(GetOuter()->GetOuter());
}

bool UFiniteStateMachineConditionBase::IsConditionMet_Implementation()
{
    return true;
}

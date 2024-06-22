// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FiniteStateMachineTaskBase.generated.h"

class UFiniteStateMachineConditionBase;

/**
 * 
 */
UCLASS(Blueprintable)
class SOUK_SCENE_API UFiniteStateMachineTaskBase : public UObject
{
	GENERATED_BODY()

public:

	UFiniteStateMachineTaskBase();

	UFUNCTION(BlueprintNativeEvent)
	void RunLogic();
	virtual void RunLogic_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EndTask();
	virtual void EndTask_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UFiniteStateMachineConditionBase>> Conditions;

	UPROPERTY(BlueprintReadOnly)
	AActor* Owner;
};

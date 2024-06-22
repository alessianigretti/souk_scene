// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FiniteStateMachineConditionBase.generated.h"

class UFiniteStateMachineTaskBase;

/**
 * 
 */
UCLASS(Blueprintable)
class SOUK_SCENE_API UFiniteStateMachineConditionBase : public UObject
{
	GENERATED_BODY()

public:

	UFiniteStateMachineConditionBase();

	UFUNCTION(BlueprintNativeEvent)
	bool IsConditionMet();
	virtual bool IsConditionMet_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UFiniteStateMachineTaskBase> Task;

	UPROPERTY(BlueprintReadOnly)
	AActor* Owner;
};

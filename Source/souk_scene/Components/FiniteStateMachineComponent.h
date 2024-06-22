// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiniteStateMachineTaskBase.h"
#include "FiniteStateMachineComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Souk), meta=(BlueprintSpawnableComponent))
class SOUK_SCENE_API UFiniteStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFiniteStateMachineComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UFiniteStateMachineTaskBase>> AllowedTasks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UFiniteStateMachineConditionBase>> AllowedConditions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UFiniteStateMachineTaskBase> RootTask;

protected:

	virtual void BeginPlay() override;

	UPROPERTY()
	UFiniteStateMachineTaskBase* CurrentTask;

	UPROPERTY()
	TMap<UClass*, UFiniteStateMachineTaskBase*> Tasks;

	UPROPERTY()
	TMap<UClass*, UFiniteStateMachineConditionBase*> Conditions;
};

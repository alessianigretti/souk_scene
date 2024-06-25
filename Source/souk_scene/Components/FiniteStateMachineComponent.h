// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiniteStateMachineTaskBase.h"
#include "GameplayTagContainer.h"
#include "FiniteStateMachineComponent.generated.h"

class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FLinkedTasks
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UFiniteStateMachineTaskBase>> LinkedTasks;
};

UCLASS(Blueprintable, ClassGroup=(Souk), meta=(BlueprintSpawnableComponent))
class SOUK_SCENE_API UFiniteStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFiniteStateMachineComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void InjectIntoCurrentTask();

	UPROPERTY(EditAnywhere)
	TMap<TSubclassOf<UFiniteStateMachineTaskBase>, FLinkedTasks> Graph;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFiniteStateMachineTaskBase> StartTask;

	UPROPERTY(BlueprintReadOnly)
	UFiniteStateMachineTaskBase* CurrentTask;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;
};

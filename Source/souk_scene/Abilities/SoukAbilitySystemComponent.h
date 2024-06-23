// Project Sparrow - 2024.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "souk_scene/Components/FiniteStateMachineTaskBase.h"
#include "SoukAbilitySystemComponent.generated.h"

class UFiniteStateMachineTaskBase;

/**
 * 
 */
UCLASS(Blueprintable)
class SOUK_SCENE_API USoukAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UFiniteStateMachineTaskBase>> StartupAbilities;
};

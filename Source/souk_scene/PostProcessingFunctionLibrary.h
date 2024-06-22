// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PostProcessingFunctionLibrary.generated.h"

struct FPostProcessSettings;

UCLASS()
class SOUK_SCENE_API UPostProcessingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	static FPostProcessSettings MakeSettingsWithFocalLength(float FocalLength);
};

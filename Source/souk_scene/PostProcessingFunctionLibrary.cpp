// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessingFunctionLibrary.h"

FPostProcessSettings UPostProcessingFunctionLibrary::MakeSettingsWithFocalLength(float FocalLength)
{
	FPostProcessSettings Settings;
	Settings.DepthOfFieldFstop = 5.0f;
	Settings.DepthOfFieldSensorWidth = 160.0f;
	Settings.DepthOfFieldFocalDistance = FocalLength + 10.f;
	Settings.bOverride_DepthOfFieldFstop = true;
	Settings.bOverride_DepthOfFieldSensorWidth = true;
	Settings.bOverride_DepthOfFieldFocalDistance = true;

	return Settings;
}

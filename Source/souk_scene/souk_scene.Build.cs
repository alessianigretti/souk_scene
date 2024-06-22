// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class souk_scene : ModuleRules
{
	public souk_scene(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

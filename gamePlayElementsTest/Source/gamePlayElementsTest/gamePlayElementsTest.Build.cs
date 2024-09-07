// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class gamePlayElementsTest : ModuleRules
{
	public gamePlayElementsTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

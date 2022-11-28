// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class islandGame : ModuleRules
{
	public islandGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

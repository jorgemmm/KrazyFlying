// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class KrazyFlying : ModuleRules
{
	public KrazyFlying(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}

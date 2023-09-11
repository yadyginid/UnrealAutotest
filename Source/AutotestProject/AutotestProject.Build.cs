// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AutotestProject : ModuleRules
{
	public AutotestProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG"});

    PrivateDependencyModuleNames.AddRange(
    new string[]
    {
        "CoreUObject",
        "Engine",
        "Slate",
        "SlateCore",
      // ... add private dependencies that you statically link with here ...	
    }
    );

    if (Target.Configuration != UnrealTargetConfiguration.Shipping)
    {
      PublicDependencyModuleNames.Add("FunctionalTesting");
    }

  }
}

// Since -2025

using UnrealBuildTool;

public class Since : ModuleRules
{
	public Since(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
			{ 	
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"EnhancedInput",
				"GameplayAbilities",
				"GameplayTasks",
				"GameplayTags",
				"UMG",
				"NetCore",
				"StructUtils",
				
			});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			
		});

		// Uncomment if you are using Slate UI
		
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class MainEngineer : ModuleRules
{
	public MainEngineer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"});

        PrivateDependencyModuleNames.AddRange(new string[] {  });




    //string ModulePath = Path.GetDirectoryName(f.CanonicalName);
       // string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
        string ThirdPartyPath = "C:/Users/kjd/Documents/Unreal Projects/MainEngineer/ThirdParty/";
        string LibrariesPath = Path.Combine(ThirdPartyPath, "mysql-8.0.13-winx64", "lib");
        string IncludesPath = Path.Combine(ThirdPartyPath, "mysql-8.0.13-winx64", "include");
        string LibraryName = Path.Combine(LibrariesPath, "libmysql.lib");
        string DllName= Path.Combine(LibrariesPath, "libmysql.dll");
        string DLLSql= Path.Combine(LibrariesPath, "sqlite3.dll");
         string LIBSql = Path.Combine(LibrariesPath, "sqlite3.lib");

         PublicAdditionalLibraries.Add(LibraryName);
         PublicIncludePaths.Add(IncludesPath);
        PublicDelayLoadDLLs.Add(DLLSql);
        PublicAdditionalLibraries.Add(LIBSql);

         PublicLibraryPaths.Add(LibrariesPath);                                                                                       
        PublicDelayLoadDLLs.Add(DllName);
      

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}

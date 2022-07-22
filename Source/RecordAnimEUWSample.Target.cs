// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RecordAnimEUWSampleTarget : TargetRules
{
	public RecordAnimEUWSampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.AddRange( new string[] { "RecordAnimEUWSampleEditor" } );
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "RecordAnimEUWSample" } );
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RecordAnimEUWSampleEditorTarget : TargetRules
{
	public RecordAnimEUWSampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange( new string[] { "RecordAnimEUWSampleEditor" } );
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "RecordAnimEUWSample" } );
	}
}

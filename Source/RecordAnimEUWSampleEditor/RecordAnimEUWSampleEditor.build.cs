using UnrealBuildTool;
 
public class RecordAnimEUWSampleEditor : ModuleRules
{
	public RecordAnimEUWSampleEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "LevelSequence", "MovieScene", "SequenceRecorder", "LevelSequenceEditor", "Blutility", "UMG", "Sequencer", "MovieScene", "SequencerScripting" });
 
		PublicIncludePaths.AddRange(new string[] {"RecordAnimEUWSampleEditor/Public"});
		PrivateIncludePaths.AddRange(new string[] {"RecordAnimEUWSampleEditor/Private"});
	}
}
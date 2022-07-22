// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorUtilityRecordAnimation.h"

#include "AnimationRecorder.h"
#include "SequenceRecorderSettings.h"
#include "ISequencer.h"
#include "LevelSequenceEditorSubsystem.h"
#include "LevelSequenceEditorBlueprintLibrary.h"
#include "ILevelSequenceEditorToolkit.h"
#include "LevelSequence.h"
#include "SequencerUtilities.h"


void UEditorUtilityRecordAnimation::NativeDestruct()
{
	const TSharedPtr<ISequencer> Sequencer = GetSequencer();
	if (Sequencer)
	{
		Sequencer->OnStopEvent().RemoveAll(this);
	}
}

bool UEditorUtilityRecordAnimation::RecordAnimation(USkeletalMeshComponent* Component, const FString& AssetPath, const FString& AssetName, FAnimationRecordingSettingsLimited InSettings, bool AutoPlay, bool AutoStop)
{
	if (AutoPlay)
	{
		ULevelSequenceEditorBlueprintLibrary::Play();
	}

	if (AutoStop)
	{
		const TSharedPtr<ISequencer> Sequencer = GetSequencer();
		if (Sequencer)
		{
			Sequencer->OnStopEvent().AddUObject(this, &UEditorUtilityRecordAnimation::StopRecordingAllAnimations);
		}
	}

	FAnimationRecordingSettings Settings = GetDefault<USequenceRecorderSettings>()->DefaultAnimationSettings;
	Settings.SampleFrameRate = InSettings.SampleFrameRate;
	Settings.Length = InSettings.Length;

	return FAnimationRecorderManager::Get().RecordAnimation(Component, AssetPath, AssetName, Settings);
}

void UEditorUtilityRecordAnimation::StopRecordingAllAnimations()
{
	if (GEditor->IsTimerManagerValid())
	{
		GEditor->GetTimerManager()->SetTimerForNextTick([this]()
			{
				FAnimationRecorderManager::Get().StopRecordingAllAnimations();
			});
	}
}

void UEditorUtilityRecordAnimation::StopRecordingAnimation(USkeletalMeshComponent* Component, bool bShowMessage)
{
	FAnimationRecorderManager::Get().StopRecordingAnimation(Component);
}

float UEditorUtilityRecordAnimation::GetCurrentRecordingTime(USkeletalMeshComponent* Component)
{
	return FAnimationRecorderManager::Get().GetCurrentRecordingTime(Component);
}

bool UEditorUtilityRecordAnimation::IsRecording()
{
	return FAnimationRecorderManager::Get().IsRecording();
}

TSharedPtr<ISequencer> UEditorUtilityRecordAnimation::GetSequencer()
{
	// Copy From ControlRigSequencerEditorLibrary.cpp
	ULevelSequence* LevelSequence = ULevelSequenceEditorBlueprintLibrary::GetCurrentLevelSequence();
	IAssetEditorInstance* AssetEditor = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->FindEditorForAsset(LevelSequence, false);
	ILevelSequenceEditorToolkit* LevelSequenceEditor = static_cast<ILevelSequenceEditorToolkit*>(AssetEditor);
	TSharedPtr<ISequencer> Sequencer = LevelSequenceEditor ? LevelSequenceEditor->GetSequencer() : nullptr;
	if (Sequencer.IsValid() == false)
	{
		UE_LOG(LogTemp, Error, TEXT("Can not open Sequencer for the LevelSequence %s"), *(LevelSequence->GetPathName()));
		}
	return Sequencer;
}
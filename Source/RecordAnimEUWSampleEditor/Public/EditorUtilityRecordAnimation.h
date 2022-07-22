// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Animation/AnimationRecordingSettings.h"
#include "SequencerBindingProxy.h"
#include "EditorUtilityRecordAnimation.generated.h"


USTRUCT(BlueprintType)
struct RECORDANIMEUWSAMPLEEDITOR_API FAnimationRecordingSettingsLimited
{
	GENERATED_BODY()

	/** Sample rate of the recorded animation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FFrameRate SampleFrameRate = FAnimationRecordingSettings::DefaultSampleFrameRate;

	/** Maximum length of the animation recorded (in seconds). If zero the animation will keep on recording until stopped. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Length = FAnimationRecordingSettings::DefaultMaximumLength;
};


UCLASS()
class RECORDANIMEUWSAMPLEEDITOR_API UEditorUtilityRecordAnimation : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	virtual void NativeDestruct() override;

	/// <summary>
	/// @param AutoStop - It will works correctly after 5.1 ( https://issues.unrealengine.com/issue/UE-158921 )
	/// </summary>
	UFUNCTION(BlueprintCallable)
	bool RecordAnimation(USkeletalMeshComponent* Component, const FString& AssetPath, const FString& AssetName, FAnimationRecordingSettingsLimited InSettings, bool AutoPlay, bool AutoStop);

	UFUNCTION(BlueprintCallable)
	void StopRecordingAllAnimations();
	UFUNCTION(BlueprintCallable)
	void StopRecordingAnimation(USkeletalMeshComponent* Component, bool bShowMessage = true);

	UFUNCTION(BlueprintCallable)
	float GetCurrentRecordingTime(USkeletalMeshComponent* Component);

	UFUNCTION(BlueprintCallable)
	bool IsRecording();

private:

	TSharedPtr<ISequencer> GetSequencer();
};
#include "RecordAnimEUWSampleEditor.h"

DEFINE_LOG_CATEGORY(RecordAnimEUWSampleEditor);

#define LOCTEXT_NAMESPACE "FRecordAnimEUWSampleEditor"

void FRecordAnimEUWSampleEditor::StartupModule()
{
	UE_LOG(RecordAnimEUWSampleEditor, Warning, TEXT("RecordAnimEUWSampleEditor module has been loaded"));
}

void FRecordAnimEUWSampleEditor::ShutdownModule()
{
	UE_LOG(RecordAnimEUWSampleEditor, Warning, TEXT("RecordAnimEUWSampleEditor module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRecordAnimEUWSampleEditor, RecordAnimEUWSampleEditor)
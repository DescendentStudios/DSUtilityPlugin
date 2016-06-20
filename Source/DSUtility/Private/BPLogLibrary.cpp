#include "DSUtilityPrivatePCH.h"
#include "StringUtilityLibrary.h"
#include "BPLogLibrary.h"

DEFINE_LOG_CATEGORY(LogBP)

void UBPLogLibrary::PrintToLog(FString LogLine, ELogLevel Level)
{
	switch(Level)
	{
	case ELogLevel::Warning:
		UE_LOG(LogBP, Warning, TEXT("%s"), *LogLine);
		break;
	case ELogLevel::Error:
		UE_LOG(LogBP, Error, TEXT("%s"), *LogLine);
		break;
	default:
		UE_LOG(LogBP, Log, TEXT("%s"), *LogLine);
	}
}
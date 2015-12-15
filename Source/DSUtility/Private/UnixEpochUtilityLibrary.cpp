// (c) 2015 Descendent Studios, Inc.

#include "DSUtilityPrivatePCH.h"
#include "UnixEpochUtilityLibrary.h"
#include "CString.h"

UUnixEpochUtilityLibrary::UUnixEpochUtilityLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

int32 UUnixEpochUtilityLibrary::TimeUntilEpochTarget(FString targetInString)
{
	int64 targetTime = TCString<TCHAR>::Atoi64(*targetInString);
	return (int32)(targetTime - FDateTime::UtcNow().ToUnixTimestamp());
}

FString UUnixEpochUtilityLibrary::EpochNow()
{
	int64 unixNow = FDateTime::UtcNow().ToUnixTimestamp();
	return FString::Printf(TEXT("%d"), unixNow);
}

FDateTime UUnixEpochUtilityLibrary::ConvertEpochStringToDateTime(FString epochString)
{
	int64 epoch = TCString<TCHAR>::Atoi64(*epochString);
	return FDateTime::FromUnixTimestamp(epoch);
}
// (c) 2015 Descendent Studios, Inc.

#pragma once

#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnixEpochUtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UUnixEpochUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:

	UFUNCTION(BlueprintPure, Category = "Unix Epoch Utility")
	static int32 TimeUntilEpochTarget(FString targetInString);

	UFUNCTION(BlueprintPure, Category = "Unix Epoch Utility")
	static FString EpochNow();
	
	UFUNCTION(BlueprintPure, Category = "Unix Epoch Utility")
	static FDateTime ConvertEpochStringToDateTime(FString epochString);
	
};

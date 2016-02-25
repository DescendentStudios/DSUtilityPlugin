// (c) 2015 Descendent Studios, Inc.

#pragma once

#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringUtilityLibrary.generated.h"

/**
*
*/
UCLASS()
class UStringUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "String > String", CompactNodeTitle = ">", Keywords = "Compare String Greater"), Category = "Utilities|String")
		static bool SGreaterThan(FString StringA, FString StringB);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "String < String", CompactNodeTitle = "<", Keywords = "Compare String Less"), Category = "Utilities|String")
		static bool SLessThan(FString StringA, FString StringB);

};
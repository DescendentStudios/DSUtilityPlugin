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

	//Merge-sorts an array of strings
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Sort Strings", CompactNodeTitle = "SORT", Keywords = "Sort String Alphabetical"), Category = "Utilities|String")
		static TArray<FString>& SortStringArray(UPARAM(ref) TArray<FString>& In);

private:
	inline static bool ConstPredicate(const FString& ip1, const FString& ip2) { return SLessThan(ip1, ip2); };

};
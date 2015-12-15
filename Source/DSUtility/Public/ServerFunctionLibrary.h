// (c) 2015 Descendent Studios, Inc.

#pragma once

#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ServerFunctionLibrary.generated.h"

/**
 * Server utility funcitons for blueprint
 */
UCLASS()
class UServerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Server Function Library")
	static void RequestExit(bool bForce=false);
	
	UFUNCTION(BlueprintPure, Category = "Server Function Library")
	static bool IsRequestingExit();

};
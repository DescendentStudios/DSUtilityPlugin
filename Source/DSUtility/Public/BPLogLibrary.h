#pragma once
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPLogLibrary.generated.h"

UENUM(BlueprintType)        //"BlueprintType" is essential specifier
enum class ELogLevel : uint8
{
	Normal			UMETA(DisplayName = "Normal Log"),
	Warning			UMETA(DisplayName = "Warning"),
	Error			UMETA(DisplayName = "Error")
};

DECLARE_LOG_CATEGORY_EXTERN(LogBP, Log, All);

/**
*
*/
UCLASS()
class UBPLogLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Logging")
	static void PrintToLog(FString LogLine, ELogLevel Level);
};
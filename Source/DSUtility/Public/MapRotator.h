// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Engine.h"
#include "MapRotator.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Config = Game)
class UMapRotator : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Map Rotation",meta = (WorldContext = "WorldContextObject"))
	FString GetNextMapInRotation(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Map Rotation", meta = (WorldContext = "WorldContextObject"))
	static UMapRotator* CreateMapRotator(UObject* WorldContextObject);
	
	UPROPERTY(Config)
	TArray<FString> MapRotation;
};

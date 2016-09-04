// Fill out your copyright notice in the Description page of Project Settings.

#include "DSUtilityPrivatePCH.h"
#include "MapRotator.h"

UMapRotator::UMapRotator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

FString UMapRotator::GetNextMapInRotation(UObject* WorldContextObject)
{
	UWorld* world = WorldContextObject->GetWorld();
	check(world);
	FString currentMap = world->GetMapName();
	UE_LOG(LogTemp, VeryVerbose, TEXT("Current map is %s."), *currentMap);
	int32 prevIndex = -1;

	for (int32 i = 0; i < MapRotation.Num(); i++)
	{
		UE_LOG(LogTemp, VeryVerbose, TEXT("MapRotation[%d] is %s."), i, *(MapRotation[i]));
		if (currentMap.Contains(MapRotation[i], ESearchCase::Type::IgnoreCase,ESearchDir::Type::FromStart))
			{
				prevIndex = i;
				break;
			}
		else
		{
			UE_LOG(LogTemp, VeryVerbose, TEXT("%s does not contain %s."), *currentMap, *(MapRotation[i]));
		}
	}

	if (MapRotation.Num() > 0)
	{
		int32 mapIndex = (prevIndex + 1) % MapRotation.Num();
		if (mapIndex >= 0 && mapIndex < MapRotation.Num())
		{
			return MapRotation[mapIndex];
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Next map not available; restarting current map."));

	return "?restart";
}

FString UMapRotator::PickGameMode()
{
	if (GameModes.Num() == 0)
	{
		return "DefaultGameMode";
	}
	int32 idx = FMath::RandRange(0, GameModes.Num() - 1);
	return GameModes[idx];
}


UMapRotator* UMapRotator::CreateMapRotator(UObject* WorldContextObject)
{
	return NewObject<UMapRotator>(WorldContextObject);
}
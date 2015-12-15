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
	int32 mapIndex = -1;

	for (int32 i = 0; i < MapRotation.Num(); i++)
	{
		if (MapRotation[i].EndsWith(currentMap))
			{
				mapIndex = i;
				break;
			}
	}

	if (MapRotation.Num() > 0)
	{
		mapIndex = (mapIndex + 1) % MapRotation.Num();
		if (mapIndex >= 0 && mapIndex < MapRotation.Num())
		{
			return MapRotation[mapIndex];
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Next map not available; restarting current map."));

	return "?restart";
}


UMapRotator* UMapRotator::CreateMapRotator(UObject* WorldContextObject)
{
	return NewObject<UMapRotator>(WorldContextObject);
}
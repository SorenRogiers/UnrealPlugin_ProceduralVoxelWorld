// Fill out your copyright notice in the Description page of Project Settings.

#include "IVW_PlayerController.h"
#include "VoxelTerrainActor.h"
#include "Engine/World.h"
#include <algorithm>
#include "Kismet/GameplayStatics.h"
#include "ConstructorHelpers.h"

TSubclassOf<class AVoxelTerrainActor> VoxelActor_BP;

AIVW_PlayerController::AIVW_PlayerController()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/InfiniteVoxelWorld/IVW_VoxelTerrainActor_BP.IVW_VoxelTerrainActor_BP'"));
	if (ItemBlueprint.Object) {
		VoxelActor_BP = (UClass*)ItemBlueprint.Object->GeneratedClass;
	}
}

void AIVW_PlayerController::Initialize()
{
	ChunkSize = VoxelElements * VoxelSize;
	ChunkSizeHalf = ChunkSize / 2;

}

bool AIVW_PlayerController::UpdatePositionAndChunk()
{
	if(GetPawn())
		CharacterPosition = GetPawn()->GetActorLocation() * FVector(1.f,1.f,0.f);

	int32 newChunkX = floor(CharacterPosition.X / ChunkSize);
	int32 newChunkY = floor(CharacterPosition.Y / ChunkSize);

	if(newChunkX != ChunkX || newChunkY != ChunkY)
	{
		ChunkX = newChunkX;
		ChunkY = newChunkY;

		return true;
	}

	return false;
}

void AIVW_PlayerController::AddChunk()
{
	for(int32 x = RenderRange * -1; x  <RenderRange; x++)
	{
		for(int32 y = RenderRange*-1; y < RenderRange;y++)
		{
			int32 xChunkIndex = x + ChunkX;
			int32 yChunkIndex = y + ChunkY;
			FVector2D chunkCoord(xChunkIndex, yChunkIndex);

			FVector spawnPosition = {};
			spawnPosition.X = xChunkIndex * ChunkSize;
			spawnPosition.Y = yChunkIndex * ChunkSize;
			spawnPosition.Z = 0;

			float middleOfChunkX = spawnPosition.X + ChunkSizeHalf;
			float middleOfChunkY = spawnPosition.Y + ChunkSizeHalf;

			auto foundCoord = ChunkCoordinates.FindByPredicate([&](const FVector2D &c) {return (chunkCoord.X == c.X && chunkCoord.Y == c.Y); });

			if(CheckRadius(middleOfChunkX,middleOfChunkY))
			{
				if (foundCoord == nullptr)
				{
					ChunkCoordinates.Add(chunkCoord);

					//Better to use BeginDeferredActorSpawnFromClass, that way the construction is ran after you initialize it.
					FTransform spawnTransform(FRotator::ZeroRotator, spawnPosition);
					AVoxelTerrainActor* actor = GetWorld()->SpawnActorDeferred<AVoxelTerrainActor>(VoxelActor_BP, spawnTransform);
					
					if (actor != nullptr)
					{
						actor->ChunkXIndex = xChunkIndex;
						actor->ChunkYIndex = yChunkIndex;

						UGameplayStatics::FinishSpawningActor(actor, spawnTransform);
					}

					Chunks.Add(actor);
				}
			}

		}
	}
	
}

void AIVW_PlayerController::RemoveChunk()
{
	for(int32 i =0 ;i < ChunkCoordinates.Num();++i)
	{
		float xRange = (ChunkCoordinates[i].X * ChunkSize) + ChunkSizeHalf;
		float yRange = (ChunkCoordinates[i].Y * ChunkSize) + ChunkSizeHalf;

		if(!CheckRadius(xRange,yRange))
		{
			Chunks[i]->Destroy();
			Chunks.RemoveAt(i);
			
			ChunkCoordinates.RemoveAt(i);
		}
	}
}

bool AIVW_PlayerController::CheckRadius(float x , float y) const
{
	FVector vector(x, y, 0);

	float vectorLength = (vector - CharacterPosition).Size();

	if (vectorLength < ChunkSize * RenderRange)
		return true;

	return false;
}

void AIVW_PlayerController::UpdateCollision()
{
	for(size_t i =0;i<Chunks.Num();++i)
	{
		if(Chunks[i]->ChunkXIndex == ChunkX && Chunks[i]->ChunkYIndex == ChunkY)
		{
			Chunks[i]->UpdateCollision(true);

		} else
		{
			Chunks[i]->UpdateCollision(false);
		}
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "IVW_PlayerController.h"
#include "VoxelTerrainActor.h"
#include "Engine/World.h"
#include <algorithm>

void AIVW_PlayerController::Initialize()
{
	ChunkSize = ChunkLineElements * VoxelSize;
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
	FTransform spawnTransform = {};

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

			float middleX = spawnPosition.X + ChunkSizeHalf;
			float middleY = spawnPosition.Y + ChunkSizeHalf;

			if(CheckRadius(middleX,middleY))
			{
				auto foundCoord = ChunkCoordinates.FindByPredicate([&](const FVector2D &c) {return (chunkCoord.X == c.X && chunkCoord.Y == c.Y); });

				if (foundCoord == nullptr)
				{
					ChunkCoordinates.Add(chunkCoord);
					FActorSpawnParameters SpawnInfo;
					auto actor = GetWorld()->SpawnActor<AVoxelTerrainActor>(AVoxelTerrainActor::StaticClass(), spawnPosition, FRotator::ZeroRotator);
				
				}
			}
		}
	}
	
}

bool AIVW_PlayerController::RemoveChunk()
{
	return false;
}

bool AIVW_PlayerController::CheckRadius(float x , float y) const
{
	FVector vector(x, y, 0);

	float vectorLength = (vector - CharacterPosition).Size();

	if (vectorLength < ChunkSize * RenderRange)
		return true;

	return false;
}

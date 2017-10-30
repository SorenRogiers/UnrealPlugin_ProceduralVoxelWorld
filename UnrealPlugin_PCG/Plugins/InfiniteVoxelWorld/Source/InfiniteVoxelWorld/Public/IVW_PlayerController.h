// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "VoxelTerrainActor.h"
#include "IVW_PlayerController.generated.h"

UCLASS()
class INFINITEVOXELWORLD_API AIVW_PlayerController : public APlayerController
{
GENERATED_BODY()
	
public:
	AIVW_PlayerController();

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UFUNCTION(BlueprintCallable)
	bool UpdatePositionAndChunk();

	UFUNCTION(BlueprintCallable)
	void UpdateCollision();

	UFUNCTION(BlueprintCallable)
	void AddChunk();

	UFUNCTION(BlueprintCallable)
	void RemoveChunk();

	bool CheckRadius(float x, float y) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RenderRange = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ChunkLineElements = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 VoxelSize = 100;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ChunkSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ChunkSizeHalf = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ChunkX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ChunkY = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CharacterPosition = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> ChunkCoordinates = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AVoxelTerrainActor*> Chunks;
};

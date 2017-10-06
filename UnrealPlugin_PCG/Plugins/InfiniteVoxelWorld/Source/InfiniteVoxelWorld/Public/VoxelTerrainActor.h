// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "VoxelTerrainActor.generated.h"

struct FVoxelData
{
	TArray<FVector> Vertices = {};
	TArray<int32> Triangles = {};
	TArray<FVector> Normals = {};
	TArray<FVector2D> UVs = {};
	TArray<FProcMeshTangent> Tangents = {};
	TArray<FColor> VertexColors = {};

	int32 ElementID = 0;
};

UCLASS()
class INFINITEVOXELWORLD_API AVoxelTerrainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelTerrainActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform & transform) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void GenerateChunks();
	void UpdateMesh();
	TArray<int32> CalculateNoise();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface *> MaterialsArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 RandomSeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 VoxelSize = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkElementsXY = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkXIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkYIndex = 0;

	UPROPERTY()
	int32 TotalChunkElements = 0;

	UPROPERTY()
	int32 ChunkElementsZ = 0;

	UPROPERTY()
	TArray<int32> ChunkIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool IsCollisionOn = false;

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float XMultiply = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float YMultiply = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ZMultiply = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Weight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float frequency = 1;
};

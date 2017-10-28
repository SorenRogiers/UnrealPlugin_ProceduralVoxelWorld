// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "FastNoise.h"
#include "Components/InstancedStaticMeshComponent.h"
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
	bool InRange(int32 value, int32 range) const;
	bool HasGrassLayerNeighbours(TArray<int32> &grid, int index);
	TArray<int32> CalculateNoise() const;
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface *> MaterialsArray;

	TArray<UStaticMesh*> StaticMesshArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 RandomSeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 VoxelSize = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkElementsXY = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkElementsZ = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkXIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkYIndex = 0;

	UPROPERTY()
	int32 TotalChunkElements = 0;

	UPROPERTY()
	TArray<int32> ChunkIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool SetColissionOn = false;

	UPROPERTY()
		int32 chunkLineElementsExt;

	UPROPERTY()
		int32 chunkLineElementsP2;

	UPROPERTY()
		int32 chunkLineElementsP2Ext;

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMeshComponent = nullptr;

	FastNoise* FastNoiseGenerator = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float TreePercentage = 0.04f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float GrassPercentage = 0.04f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float BlueOrchidPercentage = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float OxeyeDaisyPercentage = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float TulipPercentage = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float RosePercentage = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Foliage Percents")
	float PaeoniaPercentage = 0.02f;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateCollision(bool isInColissionRange);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void PlaceVoxel(FVector localPosition, int32 value);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateExtras();

	UFUNCTION(BlueprintNativeEvent)
	void AddInstanceVoxel(FVector instanceLocation, int32 type);
	virtual void AddInstanceVoxel_Implementation(FVector instanceLocation, int32 type);
};

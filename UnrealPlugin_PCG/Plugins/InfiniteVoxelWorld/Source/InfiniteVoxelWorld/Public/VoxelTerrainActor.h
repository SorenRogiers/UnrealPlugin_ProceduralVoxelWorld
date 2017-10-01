// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "VoxelTerrainActor.generated.h"

struct VoxelSection
{
	TArray<FVector> vertices = {};
	TArray<int32> triangles = {};
	TArray<FVector> normals = {};
	TArray<FVector2D> uvs = {};
	TArray<FProcMeshTangent> tangents = {};
	TArray<FColor> vertexColors = {};

	int32 elementID = 0;
};

UCLASS()
class INFINITEVOXELWORLD_API AVoxelTerrainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelTerrainActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform & transform) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface *> m_MaterialsArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 m_RandomSeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 m_VoxelSize = 200;

	UPROPERTY()
		int32 m_VoxelSizeHalf = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 m_ChunkLineElements = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 m_ChunkXIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 m_ChunkYIndex = 0;

	UPROPERTY()
		int32 m_TotalChunkElements = 0;

	UPROPERTY()
		int32 m_ChunkZElements = 80;

	UPROPERTY()
		int32 m_ChunkLineElementsP2 = 0;

	UPROPERTY()
		TArray<int32> m_ChunkFields; //type IDs 0 = grass 1 = dirt etc

	UPROPERTY()
	UProceduralMeshComponent* m_ProceduralMeshComponent = nullptr;

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

	UFUNCTION(BlueprintNativeEvent)
		TArray<int32> CalculateNoise();

	virtual TArray<int32> CalculateNoise_Implementation();
	
private:
	void GenerateChunks();
	void UpdateMesh();
};

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

UENUM(BlueprintType)
enum class EVoxelType : uint8
{
	VE_Air				UMETA(DisplayName = "Air"),
	VE_Grass 			UMETA(DisplayName = "Grass"),
	VE_Dirt 			UMETA(DisplayName = "Dirt"),
	VE_Rock 			UMETA(DisplayName = "Rock"),
	VE_Snow 			UMETA(DisplayName = "Snow"),
	VE_Sand 			UMETA(DisplayName = "Sand"),
	VE_OakLog 			UMETA(DisplayName = "OakLog"),
	VE_SpruceLog 		UMETA(DisplayName = "SpruceLog"),
	VE_OakLeaves 		UMETA(DisplayName = "OakLeaves"),
	VE_SpruceLeaves 	UMETA(DisplayName = "SpruceLeaves"),
	VE_Tallgrass 		UMETA(DisplayName = "TallGrass"),
	VE_BlueOrchid 		UMETA(DisplayName = "BlueOrchid"),
	VE_OxeyeDaisy 		UMETA(DisplayName = "OxeyeDaisy"),
	VE_Tulip	 		UMETA(DisplayName = "Tulip"),
	VE_Rose		 		UMETA(DisplayName = "Rose"),
	VE_Paeonia	 		UMETA(DisplayName = "Paeonia")
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
	void CreateChunk();
	void DrawChunk();
	void CreateTrees(FIntVector treeCenter,int32 id);
	void CreateFaces(int32 faceID,int x,int y,int z, TArray<FVector>& vertices, TArray<FVector>& normals) const;
	
	bool InRange(int32 value, int32 range) const;
	
	TArray<int32> CalculateNoise() const;
	TArray<int32> CalculateBiomeMap() const;
private:

	FastNoise* FastNoiseGenerator = nullptr;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface *> MaterialsArray;

	UPROPERTY()
	TArray<EVoxelType> VoxelIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 RandomSeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 VoxelSize = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 VoxelElementsXY = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 VoxelElementsZ = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkXIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 ChunkYIndex = 0;

	UPROPERTY()
	int32 TotalChunkElements = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool SetColissionOn = false;

	UPROPERTY()
	int32 VoxelExtension;

	UPROPERTY()
	int32 VoxelElementsPowered2;

	UPROPERTY()
	int32 VoxelExtensionPowered2;

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMeshComponent = nullptr;

	//FOLIAGE PERCENTAGES
	//*******************
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


	//PUBLIC METHODS
	//**************
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateCollision(bool isInColissionRange);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void UpdateVoxel(FVector localPosition, int32 value);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void DrawFoliage();

	UFUNCTION(BlueprintNativeEvent)
	void AddFoliageMesh(FVector instanceLocation, int32 type);
	virtual void AddFoliageMesh_Implementation(FVector instanceLocation, int32 type);
};

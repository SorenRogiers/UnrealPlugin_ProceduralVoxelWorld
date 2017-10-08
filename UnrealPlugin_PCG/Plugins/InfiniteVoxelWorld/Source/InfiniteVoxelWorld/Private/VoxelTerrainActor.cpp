// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelTerrainActor.h"
#include "SimplexNoiseLibrary.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

const int32 Triangles[] = { 2,1,0,0,3,2 };
const FVector2D UVs[] = { FVector2D(0.0f,0.0f),FVector2D(0.0f,1.f),FVector2D(1.f,1.f),FVector2D(1.f,0.f) };
const FVector Normals0[] = { FVector(0, 0, 1),FVector(0, 0, 1),FVector(0, 0, 1),FVector(0, 0, 1) };
const FVector Normals1[] = { FVector(0, 0, -1),FVector(0, 0, -1),FVector(0, 0, -1),FVector(0, 0, -1) };
const FVector Normals2[] = { FVector(0, 1, 0),FVector(0, 1, 0),FVector(0, 1, 0),FVector(0, 1, 0) };
const FVector Normals3[] = { FVector(0, -1, 0),FVector(0, -1, 0),FVector(0, -1, 0),FVector(0, -1, 0) };
const FVector Normals4[] = { FVector(1, 0, 0),FVector(1, 0, 0),FVector(1, 0, 0),FVector(1, 0, 0) };
const FVector Normals5[] = { FVector(-1, 0, 0),FVector(-1, 0, 0),FVector(-1, 0, 0),FVector(-1, 0, 0) };

//Top face - Bottom face - Front face - Back face - Left face - Right face
//If there is no nearby voxel we add a face if there is a voxel close to us we dont need to draw a face
const FVector mask[] = { FVector(0.f,0.f,1.f),FVector(0.f,0.f,-1.f), FVector(0.f,1.f,0.f),FVector(0.f,-1.f,0.f),FVector(1.f,0.f,0.f),FVector(-1.f,0.f,0.f)};

// Sets default values
AVoxelTerrainActor::AVoxelTerrainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Grass
	static ConstructorHelpers::FObjectFinder<UMaterial> grass_mat(TEXT("/Game/Materials/Grass_mat"));
	if (grass_mat.Succeeded()) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(grass_mat.Object, grass_mat.Object);
		MaterialsArray.Add(MaterialInstance);
	}

	//Snow
	static ConstructorHelpers::FObjectFinder<UMaterial> snow_mat (TEXT("/Game/Materials/Snow_mat"));
	if (snow_mat.Succeeded()) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(snow_mat.Object, snow_mat.Object);
		MaterialsArray.Add(MaterialInstance);
	}

	//Rock
	static ConstructorHelpers::FObjectFinder<UMaterial> rock_mat(TEXT("/Game/Materials/Rock_mat"));
	if (rock_mat.Succeeded()) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(rock_mat.Object, rock_mat.Object);
		MaterialsArray.Add(MaterialInstance);
	}
}

// Called when the game starts or when spawned
void AVoxelTerrainActor::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AVoxelTerrainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVoxelTerrainActor::OnConstruction(const FTransform& transform)
{
	ChunkElementsZ = 64;
	TotalChunkElements = ChunkElementsXY * ChunkElementsXY * ChunkElementsZ;

	//Creating an easy to find name for our voxel
	//Assign it to the procedural mesh component and register it
	FString voxelInfo = "Voxel_" + FString::FromInt(ChunkXIndex) + "_" + FString::FromInt(ChunkYIndex);
	FName name = FName(*voxelInfo);
	ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(this, name);
	ProceduralMeshComponent->RegisterComponent();

	RootComponent = ProceduralMeshComponent;
	RootComponent->SetWorldTransform(transform);

	Super::OnConstruction(transform);

	FastNoiseGenerator = new FastNoise();
	FastNoiseGenerator->SetNoiseType(FastNoise::Perlin);
	FastNoiseGenerator->SetSeed(12345);	

	USimplexNoiseLibrary::setNoiseSeed(2);

	GenerateChunks();
	UpdateMesh();
}

void AVoxelTerrainActor::GenerateChunks()
{
	ChunkIDs.SetNumUninitialized(TotalChunkElements);
	
	TArray<int32> heightMap = CalculateNoise();

	for (int32 x = 0; x < ChunkElementsXY; ++x)
	{
		for (int32 y = 0; y<ChunkElementsXY; ++y)
		{
			for (int32 z = 0; z< ChunkElementsZ; ++z)
			{

				int32 voxelIndex = x + (y*ChunkElementsXY) + (z*(ChunkElementsXY*ChunkElementsXY));

				//1 = SOLID - 0 = AIR
				//ChunkIDs[voxelIndex] = (z < 32  + heightMap[x + (y*ChunkElementsXY) + (z*(ChunkElementsXY*ChunkElementsXY))]) ? 1 : 0;
				
				if (z < 32 + heightMap[x + (y*ChunkElementsXY) + (z*(ChunkElementsXY*ChunkElementsXY))])
					ChunkIDs[voxelIndex] = 1;
				else
					ChunkIDs[voxelIndex] = 0;


				/*
				 * if (z == 30 + noise[x + y * chunkLineElementsExt]) chunkFields[index] = 11;
				else if (z == 29 + noise[x + y * chunkLineElementsExt]) chunkFields[index] = 12;
				else if (z < 29 + noise[x + y * chunkLineElementsExt]) chunkFields[index] = 13;
				else chunkFields[index] = 0;
				 */
			}
		}
	}
}

void AVoxelTerrainActor::UpdateMesh()
{
	TArray<FVoxelData> voxelData;
	voxelData.SetNum(MaterialsArray.Num());
	int id = 0;

	for(int x = 0; x < ChunkElementsXY; x++)
	{
		for(int y = 0; y < ChunkElementsXY; y++)
		{
			for(int z = 0; z < ChunkElementsZ; z++)
			{
				int32 voxelIndex = x + (y * ChunkElementsXY) + (z * (ChunkElementsXY*ChunkElementsXY));
				int32 meshIndex = ChunkIDs[voxelIndex];

				if(meshIndex > 0)
				{
					meshIndex--;
					TArray<FVector> &vertices = voxelData[meshIndex].Vertices;
					TArray<int32> &triangles = voxelData[meshIndex].Triangles;
					TArray<FVector> &normals = voxelData[meshIndex].Normals;
					TArray<FVector2D> &uvs = voxelData[meshIndex].UVs;
					TArray<FProcMeshTangent> &tangents = voxelData[meshIndex].Tangents;
					TArray<FColor> &vertexColors = voxelData[meshIndex].VertexColors;
					int32 elementID = voxelData[meshIndex].ElementID;

					int triangleNr = 0;
					
					//Voxel = 6 sides so create 6 faces.
					for(int i =0; i<6;i++)
					{
						int index = voxelIndex + mask[i].X + (mask[i].Y * ChunkElementsXY) + (mask[i].Z * (ChunkElementsXY*ChunkElementsXY));
						
						bool flag = false;
						if(index < ChunkIDs.Num() && index >=0)
						{
							if (ChunkIDs[index] < 2)
								flag = true;
						}

						if(flag)
						{
							triangles.Add(Triangles[0] + triangleNr + elementID);
							triangles.Add(Triangles[1] + triangleNr + elementID);
							triangles.Add(Triangles[2] + triangleNr + elementID);
							triangles.Add(Triangles[3] + triangleNr + elementID);
							triangles.Add(Triangles[4] + triangleNr + elementID);
							triangles.Add(Triangles[5] + triangleNr + elementID);
							triangleNr += 4; //Add 4 vertices to next triangle


							switch(i)
							{
								case 0:
								{
									vertices.Add(FVector(-VoxelSize/2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals0, ARRAY_COUNT(Normals0));
									break;
								}
								case 1:
								{
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals1, ARRAY_COUNT(Normals0));
									break;
								}
								case 2:
								{
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals2, ARRAY_COUNT(Normals0));
									break;
								}
								case 3:
								{
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals3, ARRAY_COUNT(Normals3));
									break;
								}
								case 4:
								{
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals4, ARRAY_COUNT(Normals4));
									break;
								}
								case 5:
								{
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
									vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

									normals.Append(Normals5, ARRAY_COUNT(Normals5));
									break;
								}
							}

							uvs.Append(UVs, ARRAY_COUNT(UVs));
							FColor color = FColor(255, 255, 255, i);
							vertexColors.Add(color);
							vertexColors.Add(color);
							vertexColors.Add(color);
							vertexColors.Add(color);
						}
					}
					id += triangleNr;
					voxelData[meshIndex].ElementID += triangleNr;
				}
			}
		}
	}
	ProceduralMeshComponent->ClearAllMeshSections();
	for (int i = 0; i < voxelData.Num(); i++)
	{
		if (voxelData[i].Vertices.Num() > 0)
			ProceduralMeshComponent->CreateMeshSection(i, voxelData[i].Vertices, voxelData[i].Triangles, voxelData[i].Normals, voxelData[i].UVs, voxelData[i].VertexColors, voxelData[i].Tangents, IsCollisionOn);
	}
}

TArray<int32> AVoxelTerrainActor::CalculateNoise() const
{
	TArray<int32> noiseArr = {};

	for (int z = 0; z<ChunkElementsZ; ++z)
	{
		for (int y = 0; y<ChunkElementsXY; ++y)
		{
			for (int x = 0; x<ChunkElementsXY; ++x)
			{
				FastNoiseGenerator->SetFrequency(0.035f);

				float perlinValue = FastNoiseGenerator->GetPerlin((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 4;

				FastNoiseGenerator->SetFrequency(0.03f);

				perlinValue += FastNoiseGenerator->GetPerlin((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 8;

				FastNoiseGenerator->SetFrequency(0.035f);

				perlinValue += FastNoiseGenerator->GetPerlin((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 16;

				FastNoiseGenerator->SetFrequency(0.11f);

				perlinValue += FMath::Clamp(FastNoiseGenerator->GetPerlin((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)), 0.0f, 5.0f) * 4;

				noiseArr.Add(perlinValue);
			}
		}
	}
	return noiseArr;
}



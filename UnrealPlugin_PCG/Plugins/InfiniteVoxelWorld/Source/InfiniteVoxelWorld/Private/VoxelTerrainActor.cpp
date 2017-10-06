// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelTerrainActor.h"
#include "SimplexNoiseLibrary.h"

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

	USimplexNoiseLibrary::setNoiseSeed(2);

	GenerateChunks();
	UpdateMesh();
}

void AVoxelTerrainActor::GenerateChunks()
{
	ChunkIDs.SetNumUninitialized(TotalChunkElements);
	TArray<int32> noise = CalculateNoise();

	for (int32 x = 0; x < ChunkElementsXY; ++x)
	{
		for (int32 y = 0; y<ChunkElementsXY; ++y)
		{
			for (int32 z = 0; z< ChunkElementsZ; ++z)
			{

				int32 voxelIndex = x + (y*ChunkElementsXY) + (z*(ChunkElementsXY*ChunkElementsXY));

				//Set voxel to Air or Solid
				ChunkIDs[voxelIndex] = (z < 30 + noise[x + y*ChunkElementsXY]) ? 1 : 0;
			}
		}
	}
}

void AVoxelTerrainActor::UpdateMesh()
{
	TArray<FVoxelData> voxelData;
	voxelData.SetNum(1);
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

TArray<int32> AVoxelTerrainActor::CalculateNoise()
{
	TArray<int32> noiseArr;
	noiseArr.Reserve(ChunkElementsXY * ChunkElementsXY);
	
	for(int32 y =0; y < ChunkElementsXY; y++)
	{
		for(int32 x =0; x < ChunkElementsXY; x++)
		{
			/*float noiseValue = 
				USimplexNoiseLibrary::SimplexNoise2D((ChunkXIndex*ChunkElementsXY + x) * 0.01f, (ChunkYIndex*ChunkElementsXY + y)*0.01f) * 4 +
				USimplexNoiseLibrary::SimplexNoise2D((ChunkXIndex*ChunkElementsXY + x) * 0.01f, (ChunkYIndex*ChunkElementsXY + y)*0.01f) * 8 +
				USimplexNoiseLibrary::SimplexNoise2D((ChunkXIndex*ChunkElementsXY + x) * 0.004f, (ChunkYIndex*ChunkElementsXY + y)*0.004f) * 16 +
				FMath::Clamp(USimplexNoiseLibrary::SimplexNoise2D((ChunkXIndex*ChunkElementsXY + x)*0.05f, (ChunkYIndex * ChunkElementsXY + y) *0.05f), 0.0f, 5.0f) * 4;*/
	
			float noiseValue =
				USimplexNoiseLibrary::SimplexNoise3D((ChunkXIndex*ChunkElementsXY + x) * 0.01f, (ChunkYIndex*ChunkElementsXY + y)*0.01f ,0.02) * 4 +
				USimplexNoiseLibrary::SimplexNoise3D((ChunkXIndex*ChunkElementsXY + x) * 0.01f, (ChunkYIndex*ChunkElementsXY + y)*0.01f, 0.02) * 8 +
				USimplexNoiseLibrary::SimplexNoise3D((ChunkXIndex*ChunkElementsXY + x) * 0.004f, (ChunkYIndex*ChunkElementsXY + y)*0.004f, 0.02) * 16 +
				FMath::Clamp(USimplexNoiseLibrary::SimplexNoise3D((ChunkXIndex*ChunkElementsXY + x)*0.05f, (ChunkYIndex * ChunkElementsXY + y) *0.05f, 0.02f), 0.0f, 5.0f) * 4;
	
			noiseArr.Add(FMath::FloorToInt(noiseValue));
		}
	}
	return noiseArr;
}


//for (int x = 0; x < Width)
//{
//	for (int y = 0; y < Depth)
//	{
//		for (int z = 0; z < Height)
//		{
//			if (z < Noise2D(x, y) * Height)
//			{
//				Array[x][y][z] = Noise3D(x, y, z)
//			}
//			else {
//				Array[x][y][z] = 0
//			}
//		}
//	}
//}

//for (int i = 0; i < CHUNKMAX_X; i++)
//	for (int j = 0; j < CHUNKMAX_Y; j++)
//		for (int k = 0; k < CHUNKMAX_Z; k++)
//			if (isSolid(perlinNoise.get(chunkPosition.x + i,
//				chunkPosition.y + j,
//				chunkPosition.z + k))
//				thisChunk[i, j, k] = new Voxel(solid);
//			else
//				thisChunk[i, j, k] = new Voxel(air);
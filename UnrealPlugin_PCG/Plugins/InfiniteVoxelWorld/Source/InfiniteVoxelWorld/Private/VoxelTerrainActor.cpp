// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelTerrainActor.h"
#include "SimplexNoiseLibrary.h"
#include "ConstructorHelpers.h"
#include "IVW_GameInstance.h"

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
const FVector Mask[] = { FVector(0.f,0.f,1.f),FVector(0.f,0.f,-1.f), FVector(0.f,1.f,0.f),FVector(0.f,-1.f,0.f),FVector(1.f,0.f,0.f),FVector(-1.f,0.f,0.f)};

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
	UIVW_GameInstance* gameInstance = nullptr;

	if(GetGameInstance() != nullptr)
	{
		gameInstance = Cast<UIVW_GameInstance>(GetGameInstance());
		RandomSeed = gameInstance->RandomSeed;
	}

	ChunkElementsZ = 64;
	chunkLineElementsExt = ChunkElementsXY + 2;
	TotalChunkElements = chunkLineElementsExt * chunkLineElementsExt * ChunkElementsZ;
	chunkLineElementsP2 = ChunkElementsXY * ChunkElementsXY;
	chunkLineElementsP2Ext = chunkLineElementsExt * chunkLineElementsExt;

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
	FastNoiseGenerator->SetNoiseType(FastNoise::Simplex);
	FastNoiseGenerator->SetSeed(RandomSeed);	

	GenerateChunks();
	UpdateMesh();
	DrawFoliage();
}

void AVoxelTerrainActor::GenerateChunks()
{
	FRandomStream stream = FRandomStream(RandomSeed);
	TArray<FIntVector> treeCenters;

	ChunkIDs.SetNumUninitialized(TotalChunkElements);
	
	TArray<int32> noise = CalculateNoise();
	TArray<int32> biomes = CalculateBiomeMap();

	//Determine Biomes (grass - snow) OR air
	for (int32 x = 0; x < chunkLineElementsExt; ++x)
	{
		for (int32 y = 0; y<chunkLineElementsExt; ++y)
		{
			for (int32 z = 0; z< ChunkElementsZ; ++z)
			{
				int32 voxelIndex = x + (y * chunkLineElementsExt) + (z * chunkLineElementsP2Ext);

				int heightmapValue = noise[voxelIndex];
				
				int biomeIndex = x + y * chunkLineElementsExt;

				if (z <= 30 + heightmapValue)
				{
					if (biomes[biomeIndex] < 0)
						ChunkIDs[voxelIndex] = EVoxelType::VE_Snow;
					else
						ChunkIDs[voxelIndex] = EVoxelType::VE_Grass;
				}
				else
					ChunkIDs[voxelIndex] = EVoxelType::VE_Air;
			}
		}
	}

	//Top layer is either grass or snow
	for(size_t i = 0; i<ChunkIDs.Num();++i)
	{
		int aboveLayer = i + (chunkLineElementsP2Ext);

		if (aboveLayer < ChunkIDs.Num() && aboveLayer >= 0)
		{
			if (ChunkIDs[aboveLayer] == EVoxelType::VE_Grass || ChunkIDs[aboveLayer] == EVoxelType::VE_Snow)
				ChunkIDs[i] = EVoxelType::VE_Dirt;
		}
			
	}

	//Start the rock layers after some layers of dirt
	for (size_t i = 0; i<ChunkIDs.Num(); ++i)
	{
		int threeLayers = i + (3*chunkLineElementsP2Ext);
		int oneLayer = i + (chunkLineElementsP2Ext);
		int secondLayers = i + (2*chunkLineElementsP2Ext);
		int belowLayer = i - chunkLineElementsP2Ext;

		if (threeLayers < ChunkIDs.Num() && threeLayers >= 0 && belowLayer < ChunkIDs.Num() && belowLayer >= 0)
			if (ChunkIDs[threeLayers] == EVoxelType::VE_Dirt && ChunkIDs[oneLayer] == EVoxelType::VE_Dirt && ChunkIDs[secondLayers] == EVoxelType::VE_Dirt && (ChunkIDs[belowLayer] != EVoxelType::VE_Grass || ChunkIDs[belowLayer] != EVoxelType::VE_Snow))
				ChunkIDs[i] = EVoxelType::VE_Rock;
	}

	// smaller range for trees - we dont want to spawn them on shared areas or edges
	for (int32 x = 2; x < chunkLineElementsExt - 2; x++)
	{
		for (int32 y = 2; y < chunkLineElementsExt - 2; y++)
		{
			for (int32 z = 0; z < ChunkElementsZ; z++)
			{				
				int32 voxelIndex = x + (y * chunkLineElementsExt) + (z * chunkLineElementsP2Ext);
				int heightmapValue = noise[voxelIndex];
				int layerBelow = x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext);
				int layersFourAbove = x + (y*chunkLineElementsExt) + ((z + 4)*chunkLineElementsP2Ext);

				//TREES
				//*****
				if (stream.FRand() < TreePercentage 
					&& z == 31 + heightmapValue 
					&& ChunkIDs[voxelIndex] == EVoxelType::VE_Air
					&& (ChunkIDs[layerBelow] == EVoxelType::VE_Grass || ChunkIDs[layerBelow] == EVoxelType::VE_Snow) 
					&& ChunkIDs[layersFourAbove] == EVoxelType::VE_Air)
				{
					CreateTrees(FIntVector(x, y, z), static_cast<int32>(ChunkIDs[layerBelow]));
				}
					
				//GRASS & FLOWERS
				//***************
				if (stream.FRand() < GrassPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && (ChunkIDs[layerBelow] == EVoxelType::VE_Grass || ChunkIDs[layerBelow] == EVoxelType::VE_Snow))
					ChunkIDs[voxelIndex] = EVoxelType::VE_Tallgrass;
				else if (stream.FRand() < BlueOrchidPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && (ChunkIDs[layerBelow] == EVoxelType::VE_Grass || ChunkIDs[layerBelow] == EVoxelType::VE_Snow))
					ChunkIDs[voxelIndex] = EVoxelType::VE_BlueOrchid;
				else if (stream.FRand() < OxeyeDaisyPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && ChunkIDs[layerBelow] == EVoxelType::VE_Grass)
					ChunkIDs[voxelIndex] = EVoxelType::VE_OxeyeDaisy;
				else if (stream.FRand() < TulipPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && ChunkIDs[layerBelow] == EVoxelType::VE_Grass)
					ChunkIDs[voxelIndex] = EVoxelType::VE_Tulip;
				else if (stream.FRand() < RosePercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && ChunkIDs[layerBelow] == EVoxelType::VE_Grass)
					ChunkIDs[voxelIndex] = EVoxelType::VE_Rose;
				else if (stream.FRand() < PaeoniaPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == EVoxelType::VE_Air && ChunkIDs[layerBelow] == EVoxelType::VE_Grass)
					ChunkIDs[voxelIndex] =EVoxelType::VE_Paeonia;
				;
			}
		}
	}
	
}
void AVoxelTerrainActor::UpdateMesh()
{
	TArray<FVoxelData> voxels;
	voxels.SetNum(MaterialsArray.Num());
	int id = 0;

	for(int x = 0; x < ChunkElementsXY; x++)
	{
		for(int y = 0; y < ChunkElementsXY; y++)
		{
			for(int z = 0; z < ChunkElementsZ; z++)
			{
				int32 voxelIndex = (x + 1) + (chunkLineElementsExt * (y + 1)) + (chunkLineElementsP2Ext * z);

				int32 voxelType = static_cast<int32>(ChunkIDs[voxelIndex]);

				if(voxelType > 0 && voxelType <9)
				{
					voxelType--;

					TArray<FVector> &vertices = voxels[voxelType].Vertices;
					TArray<int32> &triangles = voxels[voxelType].Triangles;
					TArray<FVector> &normals = voxels[voxelType].Normals;
					TArray<FVector2D> &uvs = voxels[voxelType].UVs;
					TArray<FProcMeshTangent> &tangents = voxels[voxelType].Tangents;
					TArray<FColor> &vertexColors = voxels[voxelType].VertexColors;
					int32 elementID = voxels[voxelType].ElementID;

					int triangleNr = 0;
					
					//Voxel = 6 sides so create 6 faces.
					for(int i =0; i<6;i++)
					{
						//int index = voxelIndex + Mask[i].X + (Mask[i].Y * ChunkElementsXY) + (Mask[i].Z * (ChunkElementsXY*ChunkElementsXY));
						int index = voxelIndex + Mask[i].X + (Mask[i].Y * chunkLineElementsExt) + (Mask[i].Z * chunkLineElementsP2Ext);

						bool flag = false;
						
						if (index < ChunkIDs.Num() && index >= 0)
						{
							if (ChunkIDs[index] < EVoxelType::VE_Grass || ChunkIDs[index] > EVoxelType::VE_SpruceLog)
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
							triangleNr += 4;

							switch (i)
							{
							case 0:
							{
								vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
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

								normals.Append(Normals1, ARRAY_COUNT(Normals1));
								break;
							}
							case 2:
							{
								vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
								vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
								vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
								vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

								normals.Append(Normals2, ARRAY_COUNT(Normals2));
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
					voxels[voxelType].ElementID += triangleNr;
				}
			}
		}
	}

	//Create the appropriate mesh section
	ProceduralMeshComponent->ClearAllMeshSections();
	for (int i = 0; i < voxels.Num(); i++)
	{
		if (voxels[i].Vertices.Num() > 0)
		{
			ProceduralMeshComponent->CreateMeshSection(i, voxels[i].Vertices, voxels[i].Triangles, voxels[i].Normals, voxels[i].UVs, voxels[i].VertexColors, voxels[i].Tangents, SetColissionOn);
		}
	}

	//Apply appropriate Materials
	for (int32 i = 0; i<MaterialsArray.Num(); ++i)
	{
		ProceduralMeshComponent->SetMaterial(i, MaterialsArray[i]);
	}
}

void AVoxelTerrainActor::CreateTrees(FIntVector treeCenter, int32 id)
{
	FRandomStream stream = FRandomStream(RandomSeed);

	int32 treeHeight = (id == 1) ? stream.RandRange(3, 6) : stream.RandRange(4, 8);

	//Trunk
	for (int32 h = 0; h < treeHeight; h++)
	{
		if(id == 1)
			ChunkIDs[treeCenter.X + (treeCenter.Y * chunkLineElementsExt) + ((treeCenter.Z + h) * chunkLineElementsP2Ext)] = EVoxelType::VE_OakLog;
		else if(id == 4)
			ChunkIDs[treeCenter.X + (treeCenter.Y * chunkLineElementsExt) + ((treeCenter.Z + h) * chunkLineElementsP2Ext)] = EVoxelType::VE_SpruceLog;
	}

	//Leaves
	for (int32 tree_x = -2; tree_x < 3; tree_x++)
	{
		for (int32 tree_y = -2; tree_y < 3; tree_y++)
		{
			for (int32 tree_z = 1; tree_z > -2; tree_z--)
			{
				//Tree Height + 1 at z check because we add 1 layer of leaves above it
				if (InRange(tree_x + treeCenter.X, ChunkElementsXY) && InRange(tree_y + treeCenter.Y, ChunkElementsXY) && InRange(tree_z + treeCenter.Z + treeHeight + 1, ChunkElementsZ))
				{
					int32 randomX = stream.RandRange(0, 2);
					int32 randomY = stream.RandRange(0, 2);
					int32 randomZ = stream.RandRange(0, 2);

					int xCoord = (tree_x * randomX);
					int yCoord = (tree_y * randomY);
					int zCoord = (tree_z * randomZ);

					float radius = FVector(xCoord, yCoord, zCoord).Size();

					if (radius <= 3.3)
					{
						if (stream.FRand() < 0.9 || radius <= 1.4)
						{
							int leafIndex = treeCenter.X + tree_x + (chunkLineElementsExt * (treeCenter.Y + tree_y)) + (chunkLineElementsP2Ext * (treeCenter.Z + tree_z + treeHeight));
							
							if (ChunkIDs[leafIndex] == EVoxelType::VE_Air && static_cast<EVoxelType>(id) == EVoxelType::VE_Grass)
								ChunkIDs[leafIndex] = EVoxelType::VE_OakLeaves;
							else if (ChunkIDs[leafIndex] == EVoxelType::VE_Air && static_cast<EVoxelType>(id) == EVoxelType::VE_Snow)
								ChunkIDs[leafIndex] = EVoxelType::VE_SpruceLeaves;
						}
					}
				}

			}
		}
	}
}
void AVoxelTerrainActor::DrawCube(int32 faceID, int x, int y, int z) const
{
	if(faceID ==0)
	{
		
	}
	else if(faceID ==1)
	{
		
	}
	else if (faceID ==2)
	{
		
	}
	else if(faceID ==3)
	{
		
	}
	else if(faceID ==4)
	{
		
	}
	else if(faceID ==5)
	{
		
	}
}

bool AVoxelTerrainActor::InRange(int32 value, int32 range) const
{
	return (value >= 0 && value <= range);
}

TArray<int32> AVoxelTerrainActor::CalculateNoise() const
{
	TArray<int32> noiseArr = {};
	noiseArr.Reserve(chunkLineElementsExt * chunkLineElementsExt);

	for (int z = 0; z<ChunkElementsZ; ++z)
	{
		for (int y = -1; y<=ChunkElementsXY; ++y)
		{
			for (int x = -1; x<=ChunkElementsXY; ++x)
			{
				
				FastNoiseGenerator->SetFrequency(0.035f);
				float simplexValue = FastNoiseGenerator->GetSimplex((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 4;

				FastNoiseGenerator->SetFrequency(0.03f);

				simplexValue += FastNoiseGenerator->GetSimplex((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 8;

				FastNoiseGenerator->SetFrequency(0.035f);

				simplexValue += FastNoiseGenerator->GetSimplex((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)) * 16;

				FastNoiseGenerator->SetFrequency(0.11f);

				simplexValue += FMath::Clamp(FastNoiseGenerator->GetSimplex((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y), (ChunkElementsZ + z)), 0.0f, 5.0f) * 4;

				noiseArr.Add(simplexValue);
			}
		}
	}
	return noiseArr;
}
TArray<int32> AVoxelTerrainActor::CalculateBiomeMap() const
{
	TArray<int32> biomeNoise;

	for (int y = -1; y <= ChunkElementsXY; ++y)
	{
		for (int x = -1; x <= ChunkElementsXY; ++x)
		{
			FastNoiseGenerator->SetFrequency(0.001f);
			float simplexValue = FastNoiseGenerator->GetCellular((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y)) * 4;

			FastNoiseGenerator->SetFrequency(0.005f);
			simplexValue += FastNoiseGenerator->GetCellular((ChunkXIndex*ChunkElementsXY + x), (ChunkYIndex * ChunkElementsXY + y)) * 8;

			biomeNoise.Add(simplexValue);
		}
	}
	return biomeNoise;
}

void AVoxelTerrainActor::DrawFoliage()
{
	for (int32 x = 0; x < ChunkElementsXY; x++)
	{
		for (int32 y = 0; y < ChunkElementsXY; y++)
		{
			for (int32 z = 0; z < ChunkElementsZ; z++)
			{
				int32 index = (x + 1) + (chunkLineElementsExt * (y + 1)) + (chunkLineElementsP2Ext * z);
				int32 meshIndex = static_cast<int32>(ChunkIDs[index]);

				if (meshIndex > 8 && meshIndex <= 14)
					AddFoliageMesh(FVector(x * VoxelSize, y * VoxelSize, z * VoxelSize), meshIndex-1);
				
			}
		}
	}
}
void AVoxelTerrainActor::UpdateCollision(bool isInColissionRange)
{
	if(SetColissionOn != isInColissionRange)
	{
		SetColissionOn = isInColissionRange;
		UpdateMesh();
	}
}
void AVoxelTerrainActor::UpdateVoxel(FVector localPosition, int32 value)
{
	int32 x = localPosition.X / VoxelSize+1;
	int32 y = localPosition.Y / VoxelSize+1;
	int32 z = localPosition.Z / VoxelSize;

	int32 index = x + (y * chunkLineElementsExt) + (z * chunkLineElementsP2Ext);
	UE_LOG(LogTemp, Warning, TEXT("VALUE = %d"), index);

	ChunkIDs[index] = static_cast<EVoxelType>(value);

	UpdateMesh();
}
void AVoxelTerrainActor::AddFoliageMesh_Implementation(FVector instanceLocation, int32 type)
{
}


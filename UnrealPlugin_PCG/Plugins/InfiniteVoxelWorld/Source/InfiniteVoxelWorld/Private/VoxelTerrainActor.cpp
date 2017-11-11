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

	//Creating the game instance and getting my seed from the user input.
	if(GetGameInstance() != nullptr)
	{
		gameInstance = Cast<UIVW_GameInstance>(GetGameInstance());
		RandomSeed = gameInstance->RandomSeed;
	}

	VoxelElementsZ = 64;
	VoxelExtension = VoxelElementsXY+2;
	TotalChunkElements = VoxelExtension * VoxelExtension * VoxelElementsZ;
	VoxelElementsPowered2 = VoxelElementsXY * VoxelElementsXY;

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

	CreateChunk();
	DrawChunk();
	DrawFoliage();
}

void AVoxelTerrainActor::CreateChunk()
{
	//Set the random stream to generate trees - grass - flowers.
	FRandomStream stream = FRandomStream(RandomSeed);

	VoxelIDs.SetNumUninitialized(TotalChunkElements);
	
	TArray<int32> noise = CalculateNoise();
	TArray<int32> biomes = CalculateBiomeMap();

	//Determine Biomes (grass - snow) OR air
	for (int32 x = 0; x < VoxelExtension; ++x)
	{
		for (int32 y = 0; y<VoxelExtension; ++y)
		{
			for (int32 z = 0; z< VoxelElementsZ; ++z)
			{
				int32 voxelIndex = x + (y * VoxelExtension) + (z * (VoxelExtension * VoxelExtension));

				int noiseValue = noise[voxelIndex];
				
				int biomeIndex = x + y * VoxelExtension;

				if (z <= 30 + noiseValue)
				{
					if (biomes[biomeIndex] > 7)
						VoxelIDs[voxelIndex] = EVoxelType::VE_Sand;
					else if (biomes[biomeIndex] < 0)
						VoxelIDs[voxelIndex] = EVoxelType::VE_Snow;
					else
						VoxelIDs[voxelIndex] = EVoxelType::VE_Grass;
				}
				else
					VoxelIDs[voxelIndex] = EVoxelType::VE_Air;
			}
		}
	}

	//Top layer is either grass or snow and the ones below are dirt
	for(size_t i = 0; i<VoxelIDs.Num();++i)
	{
		int aboveLayer = i + (VoxelExtension * VoxelExtension);

		if (aboveLayer < VoxelIDs.Num() && aboveLayer >= 0)
		{
			if (VoxelIDs[aboveLayer] == EVoxelType::VE_Grass || VoxelIDs[aboveLayer] == EVoxelType::VE_Snow)
				VoxelIDs[i] = EVoxelType::VE_Dirt;
		}
			
	}

	//Start the rock layers after some layers of dirt
	for (size_t i = 0; i<VoxelIDs.Num(); ++i)
	{
		bool isFourLayersDirt = false;
		
		int count = 0;
		
		for(size_t l =0; l<4;++l)
		{
			int layer = i + (l * (VoxelExtension * VoxelExtension));

			if (layer < VoxelIDs.Num() && layer > 0)
			{
				if (VoxelIDs[layer] == EVoxelType::VE_Dirt)
				{
					count++;
				}
			}
		}

		if (count > 3)
			isFourLayersDirt = true;

		if (isFourLayersDirt)
			VoxelIDs[i] = EVoxelType::VE_Rock;
	}

	// smaller range for trees - we dont want to spawn them on shared areas or edges
	for (int32 x = 2; x < VoxelExtension - 2; x++)
	{
		for (int32 y = 2; y < VoxelExtension - 2; y++)
		{
			for (int32 z = 0; z < VoxelElementsZ; z++)
			{				
				int32 voxelIndex = x + (y * VoxelExtension) + (z * (VoxelExtension * VoxelExtension));
				int heightmapValue = noise[voxelIndex];
				int layerBelow = x + (y*VoxelExtension) + ((z - 1)*(VoxelExtension * VoxelExtension));
				int layersSixAbove = x + (y*VoxelExtension) + ((z + 6)*(VoxelExtension * VoxelExtension));

				//TREES
				//*****
				if (stream.FRand() < TreePercentage 
					&& z == 31 + heightmapValue 
					&& VoxelIDs[voxelIndex] == EVoxelType::VE_Air
					&& (VoxelIDs[layerBelow] == EVoxelType::VE_Grass || VoxelIDs[layerBelow] == EVoxelType::VE_Snow) 
					&& VoxelIDs[layersSixAbove] == EVoxelType::VE_Air)
				{
					CreateTrees(FIntVector(x, y, z), static_cast<int32>(VoxelIDs[layerBelow]));
				}
					
				//GRASS & FLOWERS
				//***************
				if (stream.FRand() < GrassPercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && (VoxelIDs[layerBelow] == EVoxelType::VE_Grass || VoxelIDs[layerBelow] == EVoxelType::VE_Snow))
					VoxelIDs[voxelIndex] = EVoxelType::VE_Tallgrass;
				else if (stream.FRand() < BlueOrchidPercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && (VoxelIDs[layerBelow] == EVoxelType::VE_Grass || VoxelIDs[layerBelow] == EVoxelType::VE_Snow))
					VoxelIDs[voxelIndex] = EVoxelType::VE_BlueOrchid;
				else if (stream.FRand() < OxeyeDaisyPercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && VoxelIDs[layerBelow] == EVoxelType::VE_Grass)
					VoxelIDs[voxelIndex] = EVoxelType::VE_OxeyeDaisy;
				else if (stream.FRand() < TulipPercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && VoxelIDs[layerBelow] == EVoxelType::VE_Grass)
					VoxelIDs[voxelIndex] = EVoxelType::VE_Tulip;
				else if (stream.FRand() < RosePercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && VoxelIDs[layerBelow] == EVoxelType::VE_Grass)
					VoxelIDs[voxelIndex] = EVoxelType::VE_Rose;
				else if (stream.FRand() < PaeoniaPercentage && z == 31 + heightmapValue && VoxelIDs[voxelIndex] == EVoxelType::VE_Air && VoxelIDs[layerBelow] == EVoxelType::VE_Grass)
					VoxelIDs[voxelIndex] =EVoxelType::VE_Paeonia;
			}
		}
	}
	
}
void AVoxelTerrainActor::DrawChunk()
{
	TArray<FVoxelData> voxels;
	voxels.SetNum(VoxelMaterials.Num());

	int id = 0;

	for(int x = 0; x < VoxelElementsXY; x++)
	{
		for(int y = 0; y < VoxelElementsXY; y++)
		{
			for(int z = 0; z < VoxelElementsZ; z++)
			{
				int32 voxelIndex = (x + 1) + (VoxelExtension * (y + 1)) + ((VoxelExtension * VoxelExtension) * z);

				int32 voxelType = static_cast<int32>(VoxelIDs[voxelIndex]);

				if(voxelType > 0 && voxelType <10)
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
					
					//Depending on the mask we render a face or not.
					for(int i =0; i<6;i++)
					{
						int index = voxelIndex + Mask[i].X + (Mask[i].Y * VoxelExtension) + (Mask[i].Z * (VoxelExtension * VoxelExtension));

						bool flag = false;
						
						if (index < VoxelIDs.Num() && index >= 0)
						{
							if (VoxelIDs[index] < EVoxelType::VE_Grass || VoxelIDs[index] > EVoxelType::VE_SpruceLog)
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

							//Add faces.
							CreateFaces(i, x, y, z, vertices, normals);

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
	for (int32 i = 0; i<VoxelMaterials.Num(); ++i)
	{
			ProceduralMeshComponent->SetMaterial(i,VoxelMaterials[i]);
	}
}

void AVoxelTerrainActor::CreateTrees(FIntVector treeCenter, int32 id)
{
	FRandomStream stream = FRandomStream(RandomSeed);

	int32 treeHeight = stream.RandRange(3, 6);

	//Trunk
	for (int32 h = 0; h < treeHeight; h++)
	{
		if(id == 1)
			VoxelIDs[treeCenter.X + (treeCenter.Y * VoxelExtension) + ((treeCenter.Z + h) * (VoxelExtension * VoxelExtension))] = EVoxelType::VE_OakLog;
		else if(id == 4)
			VoxelIDs[treeCenter.X + (treeCenter.Y * VoxelExtension) + ((treeCenter.Z + h) * (VoxelExtension * VoxelExtension))] = EVoxelType::VE_SpruceLog;
	}

	//Leaves
	for (int32 tree_x = -2; tree_x < 3; tree_x++)
	{
		for (int32 tree_y = -2; tree_y < 3; tree_y++)
		{
			for (int32 tree_z = 1; tree_z > -2; tree_z--)
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
							int leafIndex = treeCenter.X + tree_x + (VoxelExtension * (treeCenter.Y + tree_y)) + ((VoxelExtension * VoxelExtension) * (treeCenter.Z + tree_z + treeHeight));
							
							if (VoxelIDs[leafIndex] == EVoxelType::VE_Air && static_cast<EVoxelType>(id) == EVoxelType::VE_Grass)
								VoxelIDs[leafIndex] = EVoxelType::VE_OakLeaves;
							else if (VoxelIDs[leafIndex] == EVoxelType::VE_Air && static_cast<EVoxelType>(id) == EVoxelType::VE_Snow)
								VoxelIDs[leafIndex] = EVoxelType::VE_SpruceLeaves;
						}
					}
				

			}
		}
	}
}
void AVoxelTerrainActor::CreateFaces(int32 faceID, int x, int y, int z, TArray<FVector>& vertices, TArray<FVector>& normals) const
{
	if(faceID ==0)
	{
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals0, ARRAY_COUNT(Normals0));
	}
	else if(faceID ==1)
	{
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals1, ARRAY_COUNT(Normals1));
	}
	else if (faceID ==2)
	{
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals2, ARRAY_COUNT(Normals2));
	}
	else if(faceID ==3)
	{
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals3, ARRAY_COUNT(Normals3));
	}
	else if(faceID ==4)
	{
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals4, ARRAY_COUNT(Normals4));
	}
	else if(faceID ==5)
	{
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), -VoxelSize / 2 + (z * VoxelSize)));
		vertices.Add(FVector(-VoxelSize / 2 + (x * VoxelSize), -VoxelSize / 2 + (y * VoxelSize), VoxelSize / 2 + (z * VoxelSize)));

		normals.Append(Normals5, ARRAY_COUNT(Normals5));
	}
}

bool AVoxelTerrainActor::InRange(int32 value, int32 range) const
{
	return (value >= 0 && value <= range);
}

TArray<int32> AVoxelTerrainActor::CalculateNoise() const
{
	TArray<int32> noiseArr = {};
	noiseArr.Reserve(VoxelExtension * VoxelExtension);

	for (int z = 0; z<VoxelElementsZ; ++z)
	{
		for (int y = -1; y<=VoxelElementsXY; ++y)
		{
			for (int x = -1; x<=VoxelElementsXY; ++x)
			{
				//Adding four layers of noise on top of each other.
				FastNoiseGenerator->SetFrequency(0.035f);
				float simplexValue = FastNoiseGenerator->GetSimplex((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y), (VoxelElementsZ + z)) * 4;

				FastNoiseGenerator->SetFrequency(0.03f);

				simplexValue += FastNoiseGenerator->GetSimplex((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y), (VoxelElementsZ + z)) * 8;

				FastNoiseGenerator->SetFrequency(0.035f);

				simplexValue += FastNoiseGenerator->GetSimplex((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y), (VoxelElementsZ + z)) * 16;

				FastNoiseGenerator->SetFrequency(0.11f);

				simplexValue += FMath::Clamp(FastNoiseGenerator->GetSimplex((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y), (VoxelElementsZ + z)), 0.0f, 5.0f) * 4;

				noiseArr.Add(simplexValue);
			}
		}
	}
	return noiseArr;
}
TArray<int32> AVoxelTerrainActor::CalculateBiomeMap() const
{
	TArray<int32> biomeNoise;

	for (int y = -1; y <= VoxelElementsXY; ++y)
	{
		for (int x = -1; x <= VoxelElementsXY; ++x)
		{
			//Generate 2 layers of cellular noise.
			FastNoiseGenerator->SetFrequency(0.001f);
			float noiseValue = FastNoiseGenerator->GetCellular((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y)) * 4;

			FastNoiseGenerator->SetFrequency(0.005f);
			noiseValue += FastNoiseGenerator->GetCellular((ChunkXIndex*VoxelElementsXY + x), (ChunkYIndex * VoxelElementsXY + y)) * 8;

			biomeNoise.Add(noiseValue);
		}
	}
	return biomeNoise;
}

//If our meshindex is higher than 9 and lower than 15 we know its grass or flowers
//So we change the mesh
void AVoxelTerrainActor::DrawFoliage()
{
	for (int32 x = 0; x < VoxelElementsXY; x++)
	{
		for (int32 y = 0; y < VoxelElementsXY; y++)
		{
			for (int32 z = 0; z < VoxelElementsZ; z++)
			{
				int32 index = (x + 1) + (VoxelExtension * (y + 1)) + ((VoxelExtension * VoxelExtension) * z);
				int32 meshIndex = static_cast<int32>(VoxelIDs[index]);

				if (meshIndex > 9 && meshIndex <= 15)
					AddFoliageMesh(FVector(x * VoxelSize, y * VoxelSize, z * VoxelSize), meshIndex - (VoxelMaterials.Num()+1));
				
			}
		}
	}
}

void AVoxelTerrainActor::UpdateCollision(bool isInColissionRange)
{
	if(SetColissionOn != isInColissionRange)
	{
		SetColissionOn = isInColissionRange;
		DrawChunk();
	}
}

void AVoxelTerrainActor::AddFoliageMesh_Implementation(FVector instanceLocation, int32 type)
{
}
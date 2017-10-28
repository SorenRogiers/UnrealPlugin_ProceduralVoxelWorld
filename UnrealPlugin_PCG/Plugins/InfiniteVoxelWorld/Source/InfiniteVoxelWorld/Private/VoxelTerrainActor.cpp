// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelTerrainActor.h"
#include "SimplexNoiseLibrary.h"
#include "ConstructorHelpers.h"

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

	//VOXEL TYPES
	//1 - GRASS VOXEL
	//2 - DIRT VOXEL
	//3 - ROCK VOXEL
	//4 - WOOD VOXEL
	//5 - LEAF VOXEL
	//6 - GRASS VOXEL
	//7 - BLUE ORCHID
	//8 - OXEYE DAISY
	//9 - TULIP
	//10 - ROSE


	////Grass
	//static ConstructorHelpers::FObjectFinder<UMaterial> grass_mat(TEXT("/InfiniteVoxelWorld/Materials/Grass_mat"));
	//if (grass_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(grass_mat.Object, grass_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////Snow
	//static ConstructorHelpers::FObjectFinder<UMaterial> dirt_mat (TEXT("/InfiniteVoxelWorld/Materials/Dirt_mat"));
	//if (dirt_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(dirt_mat.Object, dirt_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////Rock
	//static ConstructorHelpers::FObjectFinder<UMaterial> rock_mat(TEXT("/InfiniteVoxelWorld/Materials/Rock_mat"));
	//if (rock_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(rock_mat.Object, rock_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////Log01
	//static ConstructorHelpers::FObjectFinder<UMaterial> tree_mat(TEXT("/InfiniteVoxelWorld/Materials/Tree01_mat"));
	//if (tree_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(tree_mat.Object, tree_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////TreeLeaves
	//static ConstructorHelpers::FObjectFinder<UMaterial> treeleaf_mat(TEXT("/InfiniteVoxelWorld/Materials/Treeleaf_mat"));
	//if (treeleaf_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(treeleaf_mat.Object, treeleaf_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////TallGrass
	//static ConstructorHelpers::FObjectFinder<UMaterial> tallGrass_mat(TEXT("/InfiniteVoxelWorld/Materials/TallGrass_mat"));
	//if (tallGrass_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(tallGrass_mat.Object, tallGrass_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////Blue orchid
	//static ConstructorHelpers::FObjectFinder<UMaterial> blueOrchid_mat(TEXT("/InfiniteVoxelWorld/Materials/BlueOrchid_mat"));
	//if (blueOrchid_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(blueOrchid_mat.Object, blueOrchid_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////OxeyeDaisy
	//static ConstructorHelpers::FObjectFinder<UMaterial> oxeyeDaisy_mat(TEXT("/InfiniteVoxelWorld/Materials/OxeyeDaisy_mat"));
	//if (oxeyeDaisy_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(oxeyeDaisy_mat.Object, oxeyeDaisy_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	////Tulip
	//static ConstructorHelpers::FObjectFinder<UMaterial> tulip_mat(TEXT("/InfiniteVoxelWorld/Materials/Tulip_mat"));
	//if (tulip_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(tulip_mat.Object, tulip_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}
	////Rose
	//static ConstructorHelpers::FObjectFinder<UMaterial> rose_mat(TEXT("/InfiniteVoxelWorld/Materials/Rose_mat"));
	//if (rose_mat.Succeeded()) {
	//	auto* MaterialInstance = UMaterialInstanceDynamic::Create(rose_mat.Object, rose_mat.Object);
	//	MaterialsArray.Add(MaterialInstance);
	//}

	//
	////TALL GRASS MESH
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/InfiniteVoxelWorld/Meshes/GrassMesh.GrassMesh'"));
	//StaticMesshArray.Add(MeshObj.Object);
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
	FastNoiseGenerator->SetSeed(12345);	

	GenerateChunks();
	UpdateMesh();
	UpdateExtras();
}

void AVoxelTerrainActor::GenerateChunks()
{
	//TODO CHANGE SEED
	FRandomStream stream = FRandomStream(12345);
	TArray<FIntVector> treeCenters;

	ChunkIDs.SetNumUninitialized(TotalChunkElements);
	
	TArray<int32> noise = CalculateNoise();

	for (int32 x = 0; x < chunkLineElementsExt; ++x)
	{
		for (int32 y = 0; y<chunkLineElementsExt; ++y)
		{
			for (int32 z = 0; z< ChunkElementsZ; ++z)
			{
				int32 voxelIndex = x + (y * chunkLineElementsExt) + (z * chunkLineElementsP2Ext);

				int heightmapValue = noise[voxelIndex];

				if (z <= 30 + heightmapValue)
				{
					ChunkIDs[voxelIndex] = 1;
				}
				else
					ChunkIDs[voxelIndex] = 0;
			}
		}
	}

	//ONLY TOP LAYER IS GRASS
	for(size_t i = 0; i<ChunkIDs.Num();++i)
	{
		int aboveLayer = i + (chunkLineElementsP2Ext);

		if (aboveLayer < ChunkIDs.Num() && aboveLayer >= 0)
			if (ChunkIDs[aboveLayer] == 1)
				ChunkIDs[i] = 2;
	}

	for (size_t i = 0; i<ChunkIDs.Num(); ++i)
	{
		int threeLayers = i + (3*chunkLineElementsP2Ext);
		int oneLayer = i + (chunkLineElementsP2Ext);
		int secondLayers = i + (2*chunkLineElementsP2Ext);
		int belowLayer = i - chunkLineElementsP2Ext;

		if (threeLayers < ChunkIDs.Num() && threeLayers >= 0 && belowLayer < ChunkIDs.Num() && belowLayer >= 0)
			if (ChunkIDs[threeLayers] == 2 && ChunkIDs[oneLayer] == 2 && ChunkIDs[secondLayers] == 2 && ChunkIDs[belowLayer] != 1)
				ChunkIDs[i] = 3;
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

				//TREES
				if (stream.FRand() < TreePercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z + 4)*chunkLineElementsP2Ext)] == 0)
					treeCenters.Add(FIntVector(x, y, z));
			
				//GRASS & FLOWERS
				if (stream.FRand() < GrassPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 6;
				else if (stream.FRand() < BlueOrchidPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 7;
				else if (stream.FRand() < OxeyeDaisyPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 8;
				else if (stream.FRand() < TulipPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 9;
				else if (stream.FRand() < RosePercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 10;
				else if (stream.FRand() < PaeoniaPercentage && z == 31 + heightmapValue && ChunkIDs[voxelIndex] == 0 && ChunkIDs[x + (y*chunkLineElementsExt) + ((z - 1)*chunkLineElementsP2Ext)] == 1)
					ChunkIDs[voxelIndex] = 11;
				;
			}
		}
	}
	
	for(auto treeCenter : treeCenters)
	{
		int32 treeHeight = stream.RandRange(3, 6);
		
		// tree trunk
		for (int32 h = 0; h < treeHeight; h++)
		{
			ChunkIDs[treeCenter.X + (treeCenter.Y * chunkLineElementsExt) + ((treeCenter.Z + h) * chunkLineElementsP2Ext)] = 4;
		}

		// tree leaves
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
								if (ChunkIDs[leafIndex] == 0)
									ChunkIDs[leafIndex] = 5;
							}
						}
					}
					
				}
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
				//int32 voxelIndex = x + (y * ChunkElementsXY) + (z * (ChunkElementsXY*ChunkElementsXY));
				int32 voxelIndex = (x + 1) + (chunkLineElementsExt * (y + 1)) + (chunkLineElementsP2Ext * z);

				int32 voxelType = ChunkIDs[voxelIndex];

				if(voxelType > 0 && voxelType <= 5)
				{
					voxelType--;
					TArray<FVector> &vertices = voxelData[voxelType].Vertices;
					TArray<int32> &triangles = voxelData[voxelType].Triangles;
					TArray<FVector> &normals = voxelData[voxelType].Normals;
					TArray<FVector2D> &uvs = voxelData[voxelType].UVs;
					TArray<FProcMeshTangent> &tangents = voxelData[voxelType].Tangents;
					TArray<FColor> &vertexColors = voxelData[voxelType].VertexColors;
					int32 elementID = voxelData[voxelType].ElementID;

					int triangleNr = 0;
					
					//Voxel = 6 sides so create 6 faces.
					for(int i =0; i<6;i++)
					{
						//int index = voxelIndex + Mask[i].X + (Mask[i].Y * ChunkElementsXY) + (Mask[i].Z * (ChunkElementsXY*ChunkElementsXY));
						int index = voxelIndex + Mask[i].X + (Mask[i].Y * chunkLineElementsExt) + (Mask[i].Z * chunkLineElementsP2Ext);

						bool flag = false;
						
						if (index < ChunkIDs.Num() && index >= 0)
						{
							if (ChunkIDs[index] < 1 || ChunkIDs[index] >4)
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
					voxelData[voxelType].ElementID += triangleNr;
				}
			}
		}
	}
	ProceduralMeshComponent->ClearAllMeshSections();
	for (int i = 0; i < voxelData.Num(); i++)
	{
		if (voxelData[i].Vertices.Num() > 0)
		{
			ProceduralMeshComponent->CreateMeshSection(i, voxelData[i].Vertices, voxelData[i].Triangles, voxelData[i].Normals, voxelData[i].UVs, voxelData[i].VertexColors, voxelData[i].Tangents, SetColissionOn);
		}
	}

	//Materials
	for (int32 i = 0; i<MaterialsArray.Num(); ++i)
	{
		ProceduralMeshComponent->SetMaterial(i, MaterialsArray[i]);
	}
}
bool AVoxelTerrainActor::InRange(int32 value, int32 range) const
{
	return (value >= 0 && value <= range);
}
bool AVoxelTerrainActor::HasGrassLayerNeighbours(TArray<int32>& grid, int index)
{
	int count = 0;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int neighbourX = index + i;
			int neighbourY = index +j;

			if ((grid[neighbourX] == 1) && grid[neighbourY] == 1)
			{
				count++;
			}

		}
	}

	if (count == 9)
		return true;

	return false;
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
void AVoxelTerrainActor::UpdateExtras()
{
	for (int32 x = 0; x < ChunkElementsXY; x++)
	{
		for (int32 y = 0; y < ChunkElementsXY; y++)
		{
			for (int32 z = 0; z < ChunkElementsZ; z++)
			{
				int32 index = (x + 1) + (chunkLineElementsExt * (y + 1)) + (chunkLineElementsP2Ext * z);
				int32 meshIndex = ChunkIDs[index];

				if (meshIndex > 5 && meshIndex <= 11)
					AddInstanceVoxel(FVector(x * VoxelSize, y * VoxelSize, z * VoxelSize), meshIndex-1);
				
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
void AVoxelTerrainActor::PlaceVoxel(FVector localPosition, int32 value)
{
	int32 x = localPosition.X / VoxelSize+1;
	int32 y = localPosition.Y / VoxelSize+1;
	int32 z = localPosition.Z / VoxelSize;

	int32 index = x + (y * chunkLineElementsExt) + (z * chunkLineElementsP2Ext);
	UE_LOG(LogTemp, Warning, TEXT("VALUE = %d"), index);

	ChunkIDs[index] = value;

	UpdateMesh();
}
void AVoxelTerrainActor::AddInstanceVoxel_Implementation(FVector instanceLocation, int32 type)
{
}


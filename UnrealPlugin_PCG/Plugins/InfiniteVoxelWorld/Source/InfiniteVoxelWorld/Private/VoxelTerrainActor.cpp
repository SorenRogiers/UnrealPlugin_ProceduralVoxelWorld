// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelTerrainActor.h"
#include "ProceduralMeshComponent.h"

const int32 Triangles[] = { 2,1,0,0,3,2 };
const FVector2D UVs[] = { FVector2D(0.0f,0.0f),FVector2D(0.0f,1.f),FVector2D(1.f,1.f),FVector2D(1.f,0.f) };
const FVector Normals0[] = { FVector(0, 0, 1),FVector(0, 0, 1),FVector(0, 0, 1),FVector(0, 0, 1) };
const FVector Normals1[] = { FVector(0, 0, -1),FVector(0, 0, -1),FVector(0, 0, -1),FVector(0, 0, -1) };
const FVector Normals2[] = { FVector(0, 1, 0),FVector(0, 1, 0),FVector(0, 1, 0),FVector(0, 1, 0) };
const FVector Normals3[] = { FVector(0, -1, 0),FVector(0, -1, 0),FVector(0, -1, 0),FVector(0, -1, 0) };
const FVector Normals4[] = { FVector(1, 0, 0),FVector(1, 0, 0),FVector(1, 0, 0),FVector(1, 0, 0) };
const FVector Normals5[] = { FVector(-1, 0, 0),FVector(-1, 0, 0),FVector(-1, 0, 0),FVector(-1, 0, 0) };
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
	m_TotalChunkElements = m_ChunkLineElements * m_ChunkLineElements * m_ChunkZElements;
	m_ChunkLineElementsP2 = m_ChunkLineElements * m_ChunkLineElements;
	m_VoxelSizeHalf = m_VoxelSize / 2;

	FString voxelInfo = "Voxel_" + FString::FromInt(m_ChunkXIndex) + "_" + FString::FromInt(m_ChunkYIndex);
	FName name = FName(*voxelInfo);
	m_ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(this, name);
	m_ProceduralMeshComponent->RegisterComponent();

	RootComponent = m_ProceduralMeshComponent;
	RootComponent->SetWorldTransform(transform);

	Super::OnConstruction(transform);

	GenerateChunks();
	UpdateMesh();
}

TArray<int32> AVoxelTerrainActor::CalculateNoise_Implementation()
{
	TArray<int32> aa;
	aa.SetNumUninitialized(m_ChunkLineElementsP2);
	return aa;
}

void AVoxelTerrainActor::GenerateChunks()
{
	m_ChunkFields.SetNumUninitialized(m_TotalChunkElements);
	TArray<int32> noise = CalculateNoise();

	for (int32 x = 0; x < m_ChunkLineElements; ++x)
	{
		for (int32 y = 0; y<m_ChunkLineElements; ++y)
		{
			for (int32 z = 0; z< m_ChunkZElements; ++z)
			{

				int32 index = x + (y*m_ChunkLineElements) + (z*m_ChunkLineElementsP2);

				//m_ChunkFields[index] = (z < 30 + noise[x+y*m_ChunkLineElements]) ? 1 : 0;

				/*if (z == 30 + noise[x + y*m_ChunkLineElements])
					m_ChunkFields[index] = 1;
				else if (z == 29 + noise[x + y*m_ChunkLineElements])
					m_ChunkFields[index] = 2;
				else if (z < 29 + noise[x + y*m_ChunkLineElements])
					m_ChunkFields[index] = 3;
				else
					m_ChunkFields[index] = 0;*/

				m_ChunkFields[index] = (z > 30) ? 1 : 0;
			}
		}
	}
}

void AVoxelTerrainActor::UpdateMesh()
{
	TArray<FVector> vertices = {};
	TArray<int32> triangles = {};
	TArray<FVector> normals = {};
	TArray<FVector2D> uvs = {};
	TArray<FProcMeshTangent> tangents = {};
	TArray<FColor> vertexColors = {};

	int32 elementID = 0;

	for (int32 x = 0; x < m_ChunkLineElements; ++x)
	{
		for (int32 y = 0; y<m_ChunkLineElements; ++y)
		{
			for (int32 z = 0; z< m_ChunkZElements; ++z)
			{

				int32 index = x + (y*m_ChunkLineElements) + (z*m_ChunkLineElementsP2);
				int32 meshIndex = m_ChunkFields[index];

				if (meshIndex > 0)
				{
					meshIndex--;

					//Adding faces,vertices,uvs and normals
					int triangleNumber = 0;

					for (int i = 0; i< 6; i++)
					{
						int newIndex = index + Mask[i].X + (Mask[i].Y * m_ChunkLineElements) + (Mask[i].Z * m_ChunkLineElementsP2);
						bool flag = true;

						if (meshIndex >= 20)
						{
							flag = true;
						}
						else if ((x + Mask[i].X < m_ChunkLineElements) && (x + Mask[i].X >= 0) && (y + Mask[i].Y < m_ChunkLineElements) && (y + Mask[i].Y >= 0))
						{
							if (newIndex < m_ChunkFields.Num() && newIndex >= 0)
							{
								if (m_ChunkFields[newIndex] < 1)
									flag = true;
							}
						}
						else
						{
							flag = true;
						}

						if (flag)
						{
							triangles.Add(Triangles[0] + triangleNumber + elementID);
							triangles.Add(Triangles[1] + triangleNumber + elementID);
							triangles.Add(Triangles[2] + triangleNumber + elementID);
							triangles.Add(Triangles[3] + triangleNumber + elementID);
							triangles.Add(Triangles[4] + triangleNumber + elementID);
							triangles.Add(Triangles[5] + triangleNumber + elementID);
							triangleNumber += 4;	//add 4 vertices to the next triangle

							switch (i)
							{
							case 0:
							{
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));

								normals.Append(Normals0, ARRAY_COUNT(Normals0));
								break;
							}
							case 1:
							{
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));

								normals.Append(Normals1, ARRAY_COUNT(Normals1));
								break;
							}
							case 2:
							{
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));

								normals.Append(Normals2, ARRAY_COUNT(Normals2));
								break;
							}
							case 3:
							{
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));

								normals.Append(Normals3, ARRAY_COUNT(Normals3));
								break;
							}
							case 4:
							{
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));

								normals.Append(Normals4, ARRAY_COUNT(Normals4));
								break;
							}
							case 5:
							{
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), -m_VoxelSizeHalf + (z*m_VoxelSize)));
								vertices.Add(FVector(-m_VoxelSizeHalf + (x * m_VoxelSize), -m_VoxelSizeHalf + (y*m_VoxelSize), m_VoxelSizeHalf + (z*m_VoxelSize)));

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
					elementID += triangleNumber;
				}
			}
		}
	}

	m_ProceduralMeshComponent->ClearAllMeshSections();
	m_ProceduralMeshComponent->CreateMeshSection(0, vertices, triangles, normals, uvs, vertexColors, tangents, true);
}



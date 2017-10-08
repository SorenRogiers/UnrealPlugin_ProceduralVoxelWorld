// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/VoxelTerrainActor.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoxelTerrainActor() {}
// Cross Module References
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void AVoxelTerrainActor::StaticRegisterNativesAVoxelTerrainActor()
	{
	}
	UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister()
	{
		return AVoxelTerrainActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AVoxelTerrainActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_InfiniteVoxelWorld();
			OuterClass = AVoxelTerrainActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_ProceduralMeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProceduralMeshComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ProceduralMeshComponent, AVoxelTerrainActor), 0x0010000000080008, Z_Construct_UClass_UProceduralMeshComponent_NoRegister());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(IsCollisionOn, AVoxelTerrainActor);
				UProperty* NewProp_IsCollisionOn = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("IsCollisionOn"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(IsCollisionOn, AVoxelTerrainActor), 0x0011000000000005, CPP_BOOL_PROPERTY_BITMASK(IsCollisionOn, AVoxelTerrainActor), sizeof(bool), true);
				UProperty* NewProp_ChunkIDs = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkIDs"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ChunkIDs, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_ChunkIDs_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ChunkIDs, TEXT("ChunkIDs"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_TotalChunkElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TotalChunkElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(TotalChunkElements, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_ChunkYIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkYIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkYIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_ChunkXIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkXIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkXIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_ChunkElementsZ = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkElementsZ"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkElementsZ, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_ChunkElementsXY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkElementsXY"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkElementsXY, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_VoxelSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelSize, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RandomSeed, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_MaterialsArray = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(MaterialsArray, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_MaterialsArray_Inner = new(EC_InternalUseOnlyConstructor, NewProp_MaterialsArray, TEXT("MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInterface_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<AVoxelTerrainActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("VoxelTerrainActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_IsCollisionOn, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_IsCollisionOn, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_IsCollisionOn, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkIDs, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_TotalChunkElements, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkElementsZ, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkElementsZ, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkElementsZ, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkElementsXY, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkElementsXY, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkElementsXY, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_MaterialsArray, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_MaterialsArray, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelTerrainActor, 13645582);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelTerrainActor(Z_Construct_UClass_AVoxelTerrainActor, &AVoxelTerrainActor::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("AVoxelTerrainActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelTerrainActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

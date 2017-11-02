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
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_AddInstanceVoxel();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_PlaceVoxel();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateExtras();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	static FName NAME_AVoxelTerrainActor_AddInstanceVoxel = FName(TEXT("AddInstanceVoxel"));
	void AVoxelTerrainActor::AddInstanceVoxel(FVector instanceLocation, int32 type)
	{
		VoxelTerrainActor_eventAddInstanceVoxel_Parms Parms;
		Parms.instanceLocation=instanceLocation;
		Parms.type=type;
		ProcessEvent(FindFunctionChecked(NAME_AVoxelTerrainActor_AddInstanceVoxel),&Parms);
	}
	void AVoxelTerrainActor::StaticRegisterNativesAVoxelTerrainActor()
	{
		UClass* Class = AVoxelTerrainActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AddInstanceVoxel", (Native)&AVoxelTerrainActor::execAddInstanceVoxel },
			{ "PlaceVoxel", (Native)&AVoxelTerrainActor::execPlaceVoxel },
			{ "UpdateCollision", (Native)&AVoxelTerrainActor::execUpdateCollision },
			{ "UpdateExtras", (Native)&AVoxelTerrainActor::execUpdateExtras },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_AddInstanceVoxel()
	{
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AddInstanceVoxel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08820C00, 65535, sizeof(VoxelTerrainActor_eventAddInstanceVoxel_Parms));
			UProperty* NewProp_type = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("type"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(type, VoxelTerrainActor_eventAddInstanceVoxel_Parms), 0x0010000000000080);
			UProperty* NewProp_instanceLocation = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("instanceLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(instanceLocation, VoxelTerrainActor_eventAddInstanceVoxel_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_PlaceVoxel()
	{
		struct VoxelTerrainActor_eventPlaceVoxel_Parms
		{
			FVector localPosition;
			int32 value;
		};
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("PlaceVoxel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(VoxelTerrainActor_eventPlaceVoxel_Parms));
			UProperty* NewProp_value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("value"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(value, VoxelTerrainActor_eventPlaceVoxel_Parms), 0x0010000000000080);
			UProperty* NewProp_localPosition = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("localPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(localPosition, VoxelTerrainActor_eventPlaceVoxel_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Voxel"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision()
	{
		struct VoxelTerrainActor_eventUpdateCollision_Parms
		{
			bool isInColissionRange;
		};
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UpdateCollision"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(VoxelTerrainActor_eventUpdateCollision_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(isInColissionRange, VoxelTerrainActor_eventUpdateCollision_Parms);
			UProperty* NewProp_isInColissionRange = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("isInColissionRange"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(isInColissionRange, VoxelTerrainActor_eventUpdateCollision_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(isInColissionRange, VoxelTerrainActor_eventUpdateCollision_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Voxel"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateExtras()
	{
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UpdateExtras"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Voxel"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
		}
		return ReturnFunction;
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

				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_AddInstanceVoxel());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_PlaceVoxel());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_UpdateExtras());

				UProperty* NewProp_PaeoniaPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PaeoniaPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(PaeoniaPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_RosePercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RosePercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RosePercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_TulipPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TulipPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(TulipPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_OxeyeDaisyPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OxeyeDaisyPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OxeyeDaisyPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_BlueOrchidPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BlueOrchidPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BlueOrchidPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_GrassPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("GrassPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(GrassPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_TreePercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TreePercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(TreePercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_ProceduralMeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProceduralMeshComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ProceduralMeshComponent, AVoxelTerrainActor), 0x0010000000080008, Z_Construct_UClass_UProceduralMeshComponent_NoRegister());
				UProperty* NewProp_chunkLineElementsP2Ext = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkLineElementsP2Ext"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkLineElementsP2Ext, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_chunkLineElementsP2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkLineElementsP2"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkLineElementsP2, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_chunkLineElementsExt = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkLineElementsExt"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkLineElementsExt, AVoxelTerrainActor), 0x0010000000000000);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(SetColissionOn, AVoxelTerrainActor);
				UProperty* NewProp_SetColissionOn = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SetColissionOn"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(SetColissionOn, AVoxelTerrainActor), 0x0011000000000005, CPP_BOOL_PROPERTY_BITMASK(SetColissionOn, AVoxelTerrainActor), sizeof(bool), true);
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
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_AddInstanceVoxel(), "AddInstanceVoxel"); // 394879226
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_PlaceVoxel(), "PlaceVoxel"); // 2890603121
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision(), "UpdateCollision"); // 1491794431
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_UpdateExtras(), "UpdateExtras"); // 2341867508
				static TCppClassTypeInfo<TCppClassTypeTraits<AVoxelTerrainActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("VoxelTerrainActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_PaeoniaPercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_PaeoniaPercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_RosePercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_RosePercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_TulipPercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_TulipPercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_OxeyeDaisyPercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_OxeyeDaisyPercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_BlueOrchidPercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_BlueOrchidPercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_GrassPercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_GrassPercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_TreePercentage, TEXT("Category"), TEXT("Foliage Percents"));
				MetaData->SetValue(NewProp_TreePercentage, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_chunkLineElementsP2Ext, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_chunkLineElementsP2, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_chunkLineElementsExt, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
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
	IMPLEMENT_CLASS(AVoxelTerrainActor, 4062112427);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelTerrainActor(Z_Construct_UClass_AVoxelTerrainActor, &AVoxelTerrainActor::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("AVoxelTerrainActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelTerrainActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

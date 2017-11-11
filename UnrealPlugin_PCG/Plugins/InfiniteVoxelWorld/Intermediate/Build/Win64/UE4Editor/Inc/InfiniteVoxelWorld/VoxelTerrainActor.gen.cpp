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
	INFINITEVOXELWORLD_API UEnum* Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_AddFoliageMesh();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_DrawFoliage();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateVoxel();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
static UEnum* EVoxelType_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType, Z_Construct_UPackage__Script_InfiniteVoxelWorld(), TEXT("EVoxelType"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVoxelType(EVoxelType_StaticEnum, TEXT("/Script/InfiniteVoxelWorld"), TEXT("EVoxelType"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_InfiniteVoxelWorld();
		extern uint32 Get_Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVoxelType"), 0, Get_Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EVoxelType"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EVoxelType::VE_Air"), 0);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Grass"), 1);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Dirt"), 2);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Rock"), 3);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Snow"), 4);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Sand"), 5);
			EnumNames.Emplace(TEXT("EVoxelType::VE_OakLog"), 6);
			EnumNames.Emplace(TEXT("EVoxelType::VE_SpruceLog"), 7);
			EnumNames.Emplace(TEXT("EVoxelType::VE_OakLeaves"), 8);
			EnumNames.Emplace(TEXT("EVoxelType::VE_SpruceLeaves"), 9);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Tallgrass"), 10);
			EnumNames.Emplace(TEXT("EVoxelType::VE_BlueOrchid"), 11);
			EnumNames.Emplace(TEXT("EVoxelType::VE_OxeyeDaisy"), 12);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Tulip"), 13);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Rose"), 14);
			EnumNames.Emplace(TEXT("EVoxelType::VE_Paeonia"), 15);
			EnumNames.Emplace(TEXT("EVoxelType::VE_MAX"), 16);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EVoxelType");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Air.DisplayName"), TEXT("Air"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_BlueOrchid.DisplayName"), TEXT("BlueOrchid"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Dirt.DisplayName"), TEXT("Dirt"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Grass.DisplayName"), TEXT("Grass"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_OakLeaves.DisplayName"), TEXT("OakLeaves"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_OakLog.DisplayName"), TEXT("OakLog"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_OxeyeDaisy.DisplayName"), TEXT("OxeyeDaisy"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Paeonia.DisplayName"), TEXT("Paeonia"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Rock.DisplayName"), TEXT("Rock"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Rose.DisplayName"), TEXT("Rose"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Sand.DisplayName"), TEXT("Sand"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Snow.DisplayName"), TEXT("Snow"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_SpruceLeaves.DisplayName"), TEXT("SpruceLeaves"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_SpruceLog.DisplayName"), TEXT("SpruceLog"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Tallgrass.DisplayName"), TEXT("TallGrass"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Tulip.DisplayName"), TEXT("Tulip"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType_CRC() { return 354250751U; }
	static FName NAME_AVoxelTerrainActor_AddFoliageMesh = FName(TEXT("AddFoliageMesh"));
	void AVoxelTerrainActor::AddFoliageMesh(FVector instanceLocation, int32 type)
	{
		VoxelTerrainActor_eventAddFoliageMesh_Parms Parms;
		Parms.instanceLocation=instanceLocation;
		Parms.type=type;
		ProcessEvent(FindFunctionChecked(NAME_AVoxelTerrainActor_AddFoliageMesh),&Parms);
	}
	void AVoxelTerrainActor::StaticRegisterNativesAVoxelTerrainActor()
	{
		UClass* Class = AVoxelTerrainActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AddFoliageMesh", (Native)&AVoxelTerrainActor::execAddFoliageMesh },
			{ "DrawFoliage", (Native)&AVoxelTerrainActor::execDrawFoliage },
			{ "UpdateCollision", (Native)&AVoxelTerrainActor::execUpdateCollision },
			{ "UpdateVoxel", (Native)&AVoxelTerrainActor::execUpdateVoxel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_AddFoliageMesh()
	{
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AddFoliageMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08820C00, 65535, sizeof(VoxelTerrainActor_eventAddFoliageMesh_Parms));
			UProperty* NewProp_type = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("type"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(type, VoxelTerrainActor_eventAddFoliageMesh_Parms), 0x0010000000000080);
			UProperty* NewProp_instanceLocation = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("instanceLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(instanceLocation, VoxelTerrainActor_eventAddFoliageMesh_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_DrawFoliage()
	{
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("DrawFoliage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
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
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("PUBLIC METHODS"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_UpdateVoxel()
	{
		struct VoxelTerrainActor_eventUpdateVoxel_Parms
		{
			FVector localPosition;
			int32 value;
		};
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UpdateVoxel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04820401, 65535, sizeof(VoxelTerrainActor_eventUpdateVoxel_Parms));
			UProperty* NewProp_value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("value"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(value, VoxelTerrainActor_eventUpdateVoxel_Parms), 0x0010000000000080);
			UProperty* NewProp_localPosition = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("localPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(localPosition, VoxelTerrainActor_eventUpdateVoxel_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
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

				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_AddFoliageMesh());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_DrawFoliage());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision());
				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_UpdateVoxel());

				UProperty* NewProp_PaeoniaPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PaeoniaPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(PaeoniaPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_RosePercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RosePercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RosePercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_TulipPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TulipPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(TulipPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_OxeyeDaisyPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OxeyeDaisyPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OxeyeDaisyPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_BlueOrchidPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BlueOrchidPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BlueOrchidPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_GrassPercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("GrassPercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(GrassPercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_TreePercentage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TreePercentage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(TreePercentage, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_ProceduralMeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProceduralMeshComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ProceduralMeshComponent, AVoxelTerrainActor), 0x0010000000080008, Z_Construct_UClass_UProceduralMeshComponent_NoRegister());
				UProperty* NewProp_VoxelExtensionPowered2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelExtensionPowered2"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelExtensionPowered2, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_VoxelElementsPowered2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelElementsPowered2"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelElementsPowered2, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_VoxelExtension = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelExtension"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelExtension, AVoxelTerrainActor), 0x0010000000000000);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(SetColissionOn, AVoxelTerrainActor);
				UProperty* NewProp_SetColissionOn = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SetColissionOn"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(SetColissionOn, AVoxelTerrainActor), 0x0011000000000005, CPP_BOOL_PROPERTY_BITMASK(SetColissionOn, AVoxelTerrainActor), sizeof(bool), true);
				UProperty* NewProp_TotalChunkElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TotalChunkElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(TotalChunkElements, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_ChunkYIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkYIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkYIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_ChunkXIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkXIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkXIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_VoxelElementsZ = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelElementsZ"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelElementsZ, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_VoxelElementsXY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelElementsXY"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelElementsXY, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_VoxelSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelSize, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RandomSeed, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_VoxelIDs = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelIDs"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(VoxelIDs, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_VoxelIDs_Inner = new(EC_InternalUseOnlyConstructor, NewProp_VoxelIDs, TEXT("VoxelIDs"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UEnum_InfiniteVoxelWorld_EVoxelType());
				UProperty* NewProp_VoxelIDs_Inner_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_VoxelIDs_Inner, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_MaterialsArray = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(MaterialsArray, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_MaterialsArray_Inner = new(EC_InternalUseOnlyConstructor, NewProp_MaterialsArray, TEXT("MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInterface_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_AddFoliageMesh(), "AddFoliageMesh"); // 3299625426
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_DrawFoliage(), "DrawFoliage"); // 4128768090
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_UpdateCollision(), "UpdateCollision"); // 673427877
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_UpdateVoxel(), "UpdateVoxel"); // 1603237417
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
				MetaData->SetValue(NewProp_TreePercentage, TEXT("ToolTip"), TEXT("FOLIAGE PERCENTAGES"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ProceduralMeshComponent, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelExtensionPowered2, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelElementsPowered2, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelExtension, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_SetColissionOn, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_TotalChunkElements, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkYIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_ChunkXIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelElementsZ, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_VoxelElementsZ, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_VoxelElementsZ, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelElementsXY, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_VoxelElementsXY, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_VoxelElementsXY, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_VoxelIDs, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_MaterialsArray, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_MaterialsArray, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelTerrainActor, 39575613);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelTerrainActor(Z_Construct_UClass_AVoxelTerrainActor, &AVoxelTerrainActor::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("AVoxelTerrainActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelTerrainActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

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
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AVoxelTerrainActor_CalculateNoise();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	static FName NAME_AVoxelTerrainActor_CalculateNoise = FName(TEXT("CalculateNoise"));
	TArray<int32> AVoxelTerrainActor::CalculateNoise()
	{
		VoxelTerrainActor_eventCalculateNoise_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AVoxelTerrainActor_CalculateNoise),&Parms);
		return Parms.ReturnValue;
	}
	void AVoxelTerrainActor::StaticRegisterNativesAVoxelTerrainActor()
	{
		UClass* Class = AVoxelTerrainActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "CalculateNoise", (Native)&AVoxelTerrainActor::execCalculateNoise },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AVoxelTerrainActor_CalculateNoise()
	{
		UObject* Outer = Z_Construct_UClass_AVoxelTerrainActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CalculateNoise"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020C00, 65535, sizeof(VoxelTerrainActor_eventCalculateNoise_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ReturnValue, VoxelTerrainActor_eventCalculateNoise_Parms), 0x0010000000000580);
			UProperty* NewProp_ReturnValue_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
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

				OuterClass->LinkChild(Z_Construct_UFunction_AVoxelTerrainActor_CalculateNoise());

				UProperty* NewProp_frequency = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("frequency"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(frequency, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_Weight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Weight"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Weight, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_ZMultiply = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ZMultiply"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ZMultiply, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_YMultiply = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("YMultiply"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(YMultiply, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_XMultiply = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("XMultiply"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(XMultiply, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_m_ProceduralMeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ProceduralMeshComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(m_ProceduralMeshComponent, AVoxelTerrainActor), 0x0010000000080008, Z_Construct_UClass_UProceduralMeshComponent_NoRegister());
				UProperty* NewProp_m_ChunkFields = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkFields"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(m_ChunkFields, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_m_ChunkFields_Inner = new(EC_InternalUseOnlyConstructor, NewProp_m_ChunkFields, TEXT("m_ChunkFields"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_m_ChunkLineElementsP2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkLineElementsP2"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_ChunkLineElementsP2, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_m_ChunkZElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkZElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_ChunkZElements, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_m_TotalChunkElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_TotalChunkElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_TotalChunkElements, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_m_ChunkYIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkYIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_ChunkYIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_m_ChunkXIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkXIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_ChunkXIndex, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_m_ChunkLineElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_ChunkLineElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_ChunkLineElements, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_m_VoxelSizeHalf = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_VoxelSizeHalf"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_VoxelSizeHalf, AVoxelTerrainActor), 0x0010000000000000);
				UProperty* NewProp_m_VoxelSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_VoxelSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_VoxelSize, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_m_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(m_RandomSeed, AVoxelTerrainActor), 0x0011000000000005);
				UProperty* NewProp_m_MaterialsArray = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("m_MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(m_MaterialsArray, AVoxelTerrainActor), 0x0010000000000005);
				UProperty* NewProp_m_MaterialsArray_Inner = new(EC_InternalUseOnlyConstructor, NewProp_m_MaterialsArray, TEXT("m_MaterialsArray"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInterface_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AVoxelTerrainActor_CalculateNoise(), "CalculateNoise"); // 1553992228
				static TCppClassTypeInfo<TCppClassTypeTraits<AVoxelTerrainActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("VoxelTerrainActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_frequency, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_frequency, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_Weight, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_Weight, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_ZMultiply, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_ZMultiply, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_YMultiply, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_YMultiply, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_XMultiply, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_XMultiply, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ProceduralMeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_m_ProceduralMeshComponent, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ProceduralMeshComponent, TEXT("ToolTip"), TEXT("type IDs 0 = grass 1 = dirt etc"));
				MetaData->SetValue(NewProp_m_ChunkFields, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ChunkLineElementsP2, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ChunkZElements, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_TotalChunkElements, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ChunkYIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_ChunkYIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_m_ChunkYIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ChunkXIndex, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_ChunkXIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_m_ChunkXIndex, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_ChunkLineElements, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_ChunkLineElements, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_m_ChunkLineElements, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_VoxelSizeHalf, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_VoxelSize, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_VoxelSize, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_m_VoxelSize, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_RandomSeed, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_RandomSeed, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_m_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
				MetaData->SetValue(NewProp_m_MaterialsArray, TEXT("Category"), TEXT("VoxelTerrainActor"));
				MetaData->SetValue(NewProp_m_MaterialsArray, TEXT("ModuleRelativePath"), TEXT("Public/VoxelTerrainActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVoxelTerrainActor, 1145502508);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVoxelTerrainActor(Z_Construct_UClass_AVoxelTerrainActor, &AVoxelTerrainActor::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("AVoxelTerrainActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoxelTerrainActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

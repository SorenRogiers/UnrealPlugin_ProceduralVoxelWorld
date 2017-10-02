// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/IVW_PlayerController.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIVW_PlayerController() {}
// Cross Module References
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AIVW_PlayerController_AddChunk();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AIVW_PlayerController();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AIVW_PlayerController_Initialize();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AIVW_PlayerController_RemoveChunk();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_AIVW_PlayerController_UpdatePositionAndChunk();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AIVW_PlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_AVoxelTerrainActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void AIVW_PlayerController::StaticRegisterNativesAIVW_PlayerController()
	{
		UClass* Class = AIVW_PlayerController::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AddChunk", (Native)&AIVW_PlayerController::execAddChunk },
			{ "Initialize", (Native)&AIVW_PlayerController::execInitialize },
			{ "RemoveChunk", (Native)&AIVW_PlayerController::execRemoveChunk },
			{ "UpdatePositionAndChunk", (Native)&AIVW_PlayerController::execUpdatePositionAndChunk },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AIVW_PlayerController_AddChunk()
	{
		UObject* Outer = Z_Construct_UClass_AIVW_PlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AddChunk"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AIVW_PlayerController_Initialize()
	{
		UObject* Outer = Z_Construct_UClass_AIVW_PlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Initialize"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AIVW_PlayerController_RemoveChunk()
	{
		UObject* Outer = Z_Construct_UClass_AIVW_PlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RemoveChunk"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AIVW_PlayerController_UpdatePositionAndChunk()
	{
		struct IVW_PlayerController_eventUpdatePositionAndChunk_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AIVW_PlayerController();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UpdatePositionAndChunk"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(IVW_PlayerController_eventUpdatePositionAndChunk_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, IVW_PlayerController_eventUpdatePositionAndChunk_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, IVW_PlayerController_eventUpdatePositionAndChunk_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, IVW_PlayerController_eventUpdatePositionAndChunk_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AIVW_PlayerController_NoRegister()
	{
		return AIVW_PlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_AIVW_PlayerController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APlayerController();
			Z_Construct_UPackage__Script_InfiniteVoxelWorld();
			OuterClass = AIVW_PlayerController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900284u;

				OuterClass->LinkChild(Z_Construct_UFunction_AIVW_PlayerController_AddChunk());
				OuterClass->LinkChild(Z_Construct_UFunction_AIVW_PlayerController_Initialize());
				OuterClass->LinkChild(Z_Construct_UFunction_AIVW_PlayerController_RemoveChunk());
				OuterClass->LinkChild(Z_Construct_UFunction_AIVW_PlayerController_UpdatePositionAndChunk());

				UProperty* NewProp_Chunks = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Chunks"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(Chunks, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_Chunks_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Chunks, TEXT("Chunks"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AVoxelTerrainActor_NoRegister());
				UProperty* NewProp_ChunkCoordinates = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkCoordinates"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ChunkCoordinates, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkCoordinates_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ChunkCoordinates, TEXT("ChunkCoordinates"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_CharacterPosition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CharacterPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(CharacterPosition, AIVW_PlayerController), 0x0010000000000005, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RandomSeed, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkY"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkY, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkX = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkX"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkX, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkSizeHalf = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkSizeHalf"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkSizeHalf, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkSize, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_VoxelSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VoxelSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(VoxelSize, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_ChunkLineElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ChunkLineElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ChunkLineElements, AIVW_PlayerController), 0x0010000000000005);
				UProperty* NewProp_RenderRange = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RenderRange"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RenderRange, AIVW_PlayerController), 0x0010000000000005);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AIVW_PlayerController_AddChunk(), "AddChunk"); // 760264403
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AIVW_PlayerController_Initialize(), "Initialize"); // 279663566
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AIVW_PlayerController_RemoveChunk(), "RemoveChunk"); // 2423319398
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AIVW_PlayerController_UpdatePositionAndChunk(), "UpdatePositionAndChunk"); // 4258383844
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AIVW_PlayerController> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("IVW_PlayerController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_Chunks, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_Chunks, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkCoordinates, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkCoordinates, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_CharacterPosition, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_CharacterPosition, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkY, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkY, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkX, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkX, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkSizeHalf, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkSizeHalf, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkSize, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkSize, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_VoxelSize, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_ChunkLineElements, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_ChunkLineElements, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
				MetaData->SetValue(NewProp_RenderRange, TEXT("Category"), TEXT("IVW_PlayerController"));
				MetaData->SetValue(NewProp_RenderRange, TEXT("ModuleRelativePath"), TEXT("Public/IVW_PlayerController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIVW_PlayerController, 3576124255);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIVW_PlayerController(Z_Construct_UClass_AIVW_PlayerController, &AIVW_PlayerController::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("AIVW_PlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIVW_PlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

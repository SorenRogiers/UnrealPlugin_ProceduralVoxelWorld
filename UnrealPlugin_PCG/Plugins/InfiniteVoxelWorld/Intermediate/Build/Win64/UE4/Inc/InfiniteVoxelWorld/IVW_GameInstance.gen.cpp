// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/IVW_GameInstance.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIVW_GameInstance() {}
// Cross Module References
	INFINITEVOXELWORLD_API UScriptStruct* Z_Construct_UScriptStruct_FSaveData();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_UIVW_GameInstance_GetAllSaveGameSlotNames();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_UIVW_GameInstance();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_UIVW_GameInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
// End Cross Module References
class UScriptStruct* FSaveData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern INFINITEVOXELWORLD_API uint32 Get_Z_Construct_UScriptStruct_FSaveData_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSaveData, Z_Construct_UPackage__Script_InfiniteVoxelWorld(), TEXT("SaveData"), sizeof(FSaveData), Get_Z_Construct_UScriptStruct_FSaveData_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSaveData(FSaveData::StaticStruct, TEXT("/Script/InfiniteVoxelWorld"), TEXT("SaveData"), false, nullptr, nullptr);
static struct FScriptStruct_InfiniteVoxelWorld_StaticRegisterNativesFSaveData
{
	FScriptStruct_InfiniteVoxelWorld_StaticRegisterNativesFSaveData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SaveData")),new UScriptStruct::TCppStructOps<FSaveData>);
	}
} ScriptStruct_InfiniteVoxelWorld_StaticRegisterNativesFSaveData;
	UScriptStruct* Z_Construct_UScriptStruct_FSaveData()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_InfiniteVoxelWorld();
		extern uint32 Get_Z_Construct_UScriptStruct_FSaveData_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SaveData"), sizeof(FSaveData), Get_Z_Construct_UScriptStruct_FSaveData_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SaveData"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FSaveData>, EStructFlags(0x00000001));
			UProperty* NewProp_SaveTime = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("SaveTime"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(SaveTime, FSaveData), 0x0010000000000004, Z_Construct_UScriptStruct_FDateTime());
			UProperty* NewProp_SaveName = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("SaveName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SaveName, FSaveData), 0x0010000000000004);
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
			MetaData->SetValue(NewProp_SaveTime, TEXT("Category"), TEXT("SaveData"));
			MetaData->SetValue(NewProp_SaveTime, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
			MetaData->SetValue(NewProp_SaveName, TEXT("Category"), TEXT("SaveData"));
			MetaData->SetValue(NewProp_SaveName, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSaveData_CRC() { return 4201769385U; }
	void UIVW_GameInstance::StaticRegisterNativesUIVW_GameInstance()
	{
		UClass* Class = UIVW_GameInstance::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetAllSaveGameSlotNames", (Native)&UIVW_GameInstance::execGetAllSaveGameSlotNames },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_UIVW_GameInstance_GetAllSaveGameSlotNames()
	{
		struct IVW_GameInstance_eventGetAllSaveGameSlotNames_Parms
		{
			TArray<FSaveData> ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_UIVW_GameInstance();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAllSaveGameSlotNames"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(IVW_GameInstance_eventGetAllSaveGameSlotNames_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ReturnValue, IVW_GameInstance_eventGetAllSaveGameSlotNames_Parms), 0x0010000000000580);
			UProperty* NewProp_ReturnValue_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FSaveData());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("TDLHelpers"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UIVW_GameInstance_NoRegister()
	{
		return UIVW_GameInstance::StaticClass();
	}
	UClass* Z_Construct_UClass_UIVW_GameInstance()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UGameInstance();
			Z_Construct_UPackage__Script_InfiniteVoxelWorld();
			OuterClass = UIVW_GameInstance::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100088u;

				OuterClass->LinkChild(Z_Construct_UFunction_UIVW_GameInstance_GetAllSaveGameSlotNames());

				UProperty* NewProp_GameName = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("GameName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(GameName, UIVW_GameInstance), 0x0010000000000005);
				UProperty* NewProp_SeedName = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SeedName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SeedName, UIVW_GameInstance), 0x0010000000000005);
				UProperty* NewProp_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RandomSeed, UIVW_GameInstance), 0x0010000000000005);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UIVW_GameInstance_GetAllSaveGameSlotNames(), "GetAllSaveGameSlotNames"); // 163298642
				static TCppClassTypeInfo<TCppClassTypeTraits<UIVW_GameInstance> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("IVW_GameInstance.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
				MetaData->SetValue(NewProp_GameName, TEXT("Category"), TEXT("IVW_GameInstance"));
				MetaData->SetValue(NewProp_GameName, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
				MetaData->SetValue(NewProp_SeedName, TEXT("Category"), TEXT("IVW_GameInstance"));
				MetaData->SetValue(NewProp_SeedName, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("Category"), TEXT("IVW_GameInstance"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIVW_GameInstance, 1690445290);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIVW_GameInstance(Z_Construct_UClass_UIVW_GameInstance, &UIVW_GameInstance::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("UIVW_GameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIVW_GameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

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
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_UIVW_GameInstance_NoRegister();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_UIVW_GameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
// End Cross Module References
	void UIVW_GameInstance::StaticRegisterNativesUIVW_GameInstance()
	{
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


				UProperty* NewProp_RandomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RandomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(RandomSeed, UIVW_GameInstance), 0x0010000000000005);
				static TCppClassTypeInfo<TCppClassTypeTraits<UIVW_GameInstance> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("IVW_GameInstance.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("Category"), TEXT("IVW_GameInstance"));
				MetaData->SetValue(NewProp_RandomSeed, TEXT("ModuleRelativePath"), TEXT("Public/IVW_GameInstance.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIVW_GameInstance, 247643732);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIVW_GameInstance(Z_Construct_UClass_UIVW_GameInstance, &UIVW_GameInstance::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("UIVW_GameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIVW_GameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

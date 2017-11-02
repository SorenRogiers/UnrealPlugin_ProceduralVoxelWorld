// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/SimplexNoiseLibrary.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimplexNoiseLibrary() {}
// Cross Module References
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_setNoiseSeed();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_USimplexNoiseLibrary();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise1D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise2D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise3D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise4D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange1D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange2D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange3D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange4D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled1D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled2D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled3D();
	INFINITEVOXELWORLD_API UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled4D();
	INFINITEVOXELWORLD_API UClass* Z_Construct_UClass_USimplexNoiseLibrary_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_InfiniteVoxelWorld();
// End Cross Module References
	void USimplexNoiseLibrary::StaticRegisterNativesUSimplexNoiseLibrary()
	{
		UClass* Class = USimplexNoiseLibrary::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "setNoiseSeed", (Native)&USimplexNoiseLibrary::execsetNoiseSeed },
			{ "SimplexNoise1D", (Native)&USimplexNoiseLibrary::execSimplexNoise1D },
			{ "SimplexNoise2D", (Native)&USimplexNoiseLibrary::execSimplexNoise2D },
			{ "SimplexNoise3D", (Native)&USimplexNoiseLibrary::execSimplexNoise3D },
			{ "SimplexNoise4D", (Native)&USimplexNoiseLibrary::execSimplexNoise4D },
			{ "SimplexNoiseInRange1D", (Native)&USimplexNoiseLibrary::execSimplexNoiseInRange1D },
			{ "SimplexNoiseInRange2D", (Native)&USimplexNoiseLibrary::execSimplexNoiseInRange2D },
			{ "SimplexNoiseInRange3D", (Native)&USimplexNoiseLibrary::execSimplexNoiseInRange3D },
			{ "SimplexNoiseInRange4D", (Native)&USimplexNoiseLibrary::execSimplexNoiseInRange4D },
			{ "SimplexNoiseScaled1D", (Native)&USimplexNoiseLibrary::execSimplexNoiseScaled1D },
			{ "SimplexNoiseScaled2D", (Native)&USimplexNoiseLibrary::execSimplexNoiseScaled2D },
			{ "SimplexNoiseScaled3D", (Native)&USimplexNoiseLibrary::execSimplexNoiseScaled3D },
			{ "SimplexNoiseScaled4D", (Native)&USimplexNoiseLibrary::execSimplexNoiseScaled4D },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_setNoiseSeed()
	{
		struct SimplexNoiseLibrary_eventsetNoiseSeed_Parms
		{
			int32 newSeed;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("setNoiseSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04422401, 65535, sizeof(SimplexNoiseLibrary_eventsetNoiseSeed_Parms));
			UProperty* NewProp_newSeed = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("newSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(newSeed, SimplexNoiseLibrary_eventsetNoiseSeed_Parms), 0x0010000008000182);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
			MetaData->SetValue(NewProp_newSeed, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise1D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoise1D_Parms
		{
			float x;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoise1D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoise1D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoise1D_Parms), 0x0010000000000580);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoise1D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise2D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoise2D_Parms
		{
			float x;
			float y;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoise2D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoise2D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoise2D_Parms), 0x0010000000000580);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoise2D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoise2D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise3D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoise3D_Parms
		{
			float x;
			float y;
			float z;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoise3D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoise3D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoise3D_Parms), 0x0010000000000580);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoise3D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoise3D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoise3D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise4D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoise4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoise4D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoise4D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoise4D_Parms), 0x0010000000000580);
			UProperty* NewProp_w = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("w"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(w, SimplexNoiseLibrary_eventSimplexNoise4D_Parms), 0x0010000000000080);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoise4D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoise4D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoise4D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange1D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms
		{
			float x;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseInRange1D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms), 0x0010000000000580);
			UProperty* NewProp_rangeMax = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMax"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMax, SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms), 0x0010000000000080);
			UProperty* NewProp_rangeMin = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMin"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMin, SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseInRange1D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Return value in Range between two float numbers\nReturn Value is scaled by difference between rangeMin & rangeMax value"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange2D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms
		{
			float x;
			float y;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseInRange2D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms), 0x0010000000000580);
			UProperty* NewProp_rangeMax = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMax"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMax, SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms), 0x0010000000000080);
			UProperty* NewProp_rangeMin = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMin"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMin, SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseInRange2D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange3D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms
		{
			float x;
			float y;
			float z;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseInRange3D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000580);
			UProperty* NewProp_rangeMax = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMax"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMax, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000080);
			UProperty* NewProp_rangeMin = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMin"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMin, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000080);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseInRange3D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange4D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float rangeMin;
			float rangeMax;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseInRange4D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000580);
			UProperty* NewProp_rangeMax = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMax"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMax, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			UProperty* NewProp_rangeMin = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("rangeMin"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(rangeMin, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			UProperty* NewProp_w = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("w"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(w, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseInRange4D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled1D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseScaled1D_Parms
		{
			float x;
			float s;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseScaled1D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseScaled1D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseScaled1D_Parms), 0x0010000000000580);
			UProperty* NewProp_s = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("s"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(s, SimplexNoiseLibrary_eventSimplexNoiseScaled1D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseScaled1D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Scaled by float value"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled2D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms
		{
			float x;
			float y;
			float s;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseScaled2D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms), 0x0010000000000580);
			UProperty* NewProp_s = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("s"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(s, SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseScaled2D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled3D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms
		{
			float x;
			float y;
			float z;
			float s;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseScaled3D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms), 0x0010000000000580);
			UProperty* NewProp_s = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("s"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(s, SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms), 0x0010000000000080);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseScaled3D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled4D()
	{
		struct SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms
		{
			float x;
			float y;
			float z;
			float w;
			float s;
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_USimplexNoiseLibrary();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SimplexNoiseScaled4D"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000580);
			UProperty* NewProp_s = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("s"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(s, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000080);
			UProperty* NewProp_w = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("w"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(w, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000080);
			UProperty* NewProp_z = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("z"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(z, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000080);
			UProperty* NewProp_y = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("y"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(y, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000080);
			UProperty* NewProp_x = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("x"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(x, SimplexNoiseLibrary_eventSimplexNoiseScaled4D_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("SimplexNoise"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USimplexNoiseLibrary_NoRegister()
	{
		return USimplexNoiseLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_USimplexNoiseLibrary()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_InfiniteVoxelWorld();
			OuterClass = USimplexNoiseLibrary::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;

				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_setNoiseSeed());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise1D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise2D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise3D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise4D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange1D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange2D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange3D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange4D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled1D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled2D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled3D());
				OuterClass->LinkChild(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled4D());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_setNoiseSeed(), "setNoiseSeed"); // 1991478929
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise1D(), "SimplexNoise1D"); // 316862054
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise2D(), "SimplexNoise2D"); // 58408939
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise3D(), "SimplexNoise3D"); // 1415530156
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoise4D(), "SimplexNoise4D"); // 3307030418
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange1D(), "SimplexNoiseInRange1D"); // 2593958697
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange2D(), "SimplexNoiseInRange2D"); // 2719405232
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange3D(), "SimplexNoiseInRange3D"); // 2780026585
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseInRange4D(), "SimplexNoiseInRange4D"); // 3316077967
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled1D(), "SimplexNoiseScaled1D"); // 810171179
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled2D(), "SimplexNoiseScaled2D"); // 3665220151
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled3D(), "SimplexNoiseScaled3D"); // 2219400426
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USimplexNoiseLibrary_SimplexNoiseScaled4D(), "SimplexNoiseScaled4D"); // 2663027579
				static TCppClassTypeInfo<TCppClassTypeTraits<USimplexNoiseLibrary> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SimplexNoiseLibrary.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SimplexNoiseLibrary.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(USimplexNoiseLibrary, 2301621603);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USimplexNoiseLibrary(Z_Construct_UClass_USimplexNoiseLibrary, &USimplexNoiseLibrary::StaticClass, TEXT("/Script/InfiniteVoxelWorld"), TEXT("USimplexNoiseLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USimplexNoiseLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION

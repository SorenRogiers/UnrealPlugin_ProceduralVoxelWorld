// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INFINITEVOXELWORLD_SimplexNoiseLibrary_generated_h
#error "SimplexNoiseLibrary.generated.h already included, missing '#pragma once' in SimplexNoiseLibrary.h"
#endif
#define INFINITEVOXELWORLD_SimplexNoiseLibrary_generated_h

#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange2D(Z_Param_x,Z_Param_y,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange1D(Z_Param_x,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled2D(Z_Param_x,Z_Param_y,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled1D(Z_Param_x,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise3D(Z_Param_x,Z_Param_y,Z_Param_z); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise2D(Z_Param_x,Z_Param_y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise1D(Z_Param_x); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetNoiseSeed) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_newSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USimplexNoiseLibrary::setNoiseSeed(Z_Param_Out_newSeed); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange2D(Z_Param_x,Z_Param_y,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseInRange1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMin); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rangeMax); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseInRange1D(Z_Param_x,Z_Param_rangeMin,Z_Param_rangeMax); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled3D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled2D(Z_Param_x,Z_Param_y,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoiseScaled1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoiseScaled1D(Z_Param_x,Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise4D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_w); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise4D(Z_Param_x,Z_Param_y,Z_Param_z,Z_Param_w); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise3D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_z); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise3D(Z_Param_x,Z_Param_y,Z_Param_z); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise2D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_y); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise2D(Z_Param_x,Z_Param_y); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimplexNoise1D) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_x); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USimplexNoiseLibrary::SimplexNoise1D(Z_Param_x); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetNoiseSeed) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_newSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USimplexNoiseLibrary::setNoiseSeed(Z_Param_Out_newSeed); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSimplexNoiseLibrary(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_USimplexNoiseLibrary(); \
public: \
	DECLARE_CLASS(USimplexNoiseLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(USimplexNoiseLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_INCLASS \
private: \
	static void StaticRegisterNativesUSimplexNoiseLibrary(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_USimplexNoiseLibrary(); \
public: \
	DECLARE_CLASS(USimplexNoiseLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(USimplexNoiseLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimplexNoiseLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimplexNoiseLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimplexNoiseLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimplexNoiseLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USimplexNoiseLibrary(USimplexNoiseLibrary&&); \
	NO_API USimplexNoiseLibrary(const USimplexNoiseLibrary&); \
public:


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimplexNoiseLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USimplexNoiseLibrary(USimplexNoiseLibrary&&); \
	NO_API USimplexNoiseLibrary(const USimplexNoiseLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimplexNoiseLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimplexNoiseLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimplexNoiseLibrary)


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_PRIVATE_PROPERTY_OFFSET
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_7_PROLOG
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_RPC_WRAPPERS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_INCLASS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_INCLASS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_SimplexNoiseLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

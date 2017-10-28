// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef INFINITEVOXELWORLD_VoxelTerrainActor_generated_h
#error "VoxelTerrainActor.generated.h already included, missing '#pragma once' in VoxelTerrainActor.h"
#endif
#define INFINITEVOXELWORLD_VoxelTerrainActor_generated_h

#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_RPC_WRAPPERS \
	virtual void AddInstanceVoxel_Implementation(FVector instanceLocation, int32 type); \
 \
	DECLARE_FUNCTION(execAddInstanceVoxel) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_instanceLocation); \
		P_GET_PROPERTY(UIntProperty,Z_Param_type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddInstanceVoxel_Implementation(Z_Param_instanceLocation,Z_Param_type); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateExtras) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateExtras(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaceVoxel) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_localPosition); \
		P_GET_PROPERTY(UIntProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlaceVoxel(Z_Param_localPosition,Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCollision) \
	{ \
		P_GET_UBOOL(Z_Param_isInColissionRange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCollision(Z_Param_isInColissionRange); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddInstanceVoxel) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_instanceLocation); \
		P_GET_PROPERTY(UIntProperty,Z_Param_type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddInstanceVoxel_Implementation(Z_Param_instanceLocation,Z_Param_type); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateExtras) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateExtras(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlaceVoxel) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_localPosition); \
		P_GET_PROPERTY(UIntProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlaceVoxel(Z_Param_localPosition,Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCollision) \
	{ \
		P_GET_UBOOL(Z_Param_isInColissionRange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCollision(Z_Param_isInColissionRange); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_EVENT_PARMS \
	struct VoxelTerrainActor_eventAddInstanceVoxel_Parms \
	{ \
		FVector instanceLocation; \
		int32 type; \
	};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_CALLBACK_WRAPPERS
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVoxelTerrainActor(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_AVoxelTerrainActor(); \
public: \
	DECLARE_CLASS(AVoxelTerrainActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(AVoxelTerrainActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAVoxelTerrainActor(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_AVoxelTerrainActor(); \
public: \
	DECLARE_CLASS(AVoxelTerrainActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(AVoxelTerrainActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVoxelTerrainActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVoxelTerrainActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelTerrainActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelTerrainActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelTerrainActor(AVoxelTerrainActor&&); \
	NO_API AVoxelTerrainActor(const AVoxelTerrainActor&); \
public:


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVoxelTerrainActor(AVoxelTerrainActor&&); \
	NO_API AVoxelTerrainActor(const AVoxelTerrainActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVoxelTerrainActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVoxelTerrainActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVoxelTerrainActor)


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_PRIVATE_PROPERTY_OFFSET
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_24_PROLOG \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_EVENT_PARMS


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_RPC_WRAPPERS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_CALLBACK_WRAPPERS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_INCLASS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_CALLBACK_WRAPPERS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_INCLASS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_VoxelTerrainActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

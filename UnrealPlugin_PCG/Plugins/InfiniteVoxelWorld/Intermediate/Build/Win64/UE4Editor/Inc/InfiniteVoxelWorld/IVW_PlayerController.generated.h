// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INFINITEVOXELWORLD_IVW_PlayerController_generated_h
#error "IVW_PlayerController.generated.h already included, missing '#pragma once' in IVW_PlayerController.h"
#endif
#define INFINITEVOXELWORLD_IVW_PlayerController_generated_h

#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRemoveChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCollision) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCollision(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdatePositionAndChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->UpdatePositionAndChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Initialize(); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRemoveChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCollision) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCollision(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdatePositionAndChunk) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->UpdatePositionAndChunk(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Initialize(); \
		P_NATIVE_END; \
	}


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAIVW_PlayerController(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_AIVW_PlayerController(); \
public: \
	DECLARE_CLASS(AIVW_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(AIVW_PlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAIVW_PlayerController(); \
	friend INFINITEVOXELWORLD_API class UClass* Z_Construct_UClass_AIVW_PlayerController(); \
public: \
	DECLARE_CLASS(AIVW_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/InfiniteVoxelWorld"), NO_API) \
	DECLARE_SERIALIZER(AIVW_PlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AIVW_PlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AIVW_PlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AIVW_PlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIVW_PlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AIVW_PlayerController(AIVW_PlayerController&&); \
	NO_API AIVW_PlayerController(const AIVW_PlayerController&); \
public:


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AIVW_PlayerController(AIVW_PlayerController&&); \
	NO_API AIVW_PlayerController(const AIVW_PlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AIVW_PlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIVW_PlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AIVW_PlayerController)


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_PRIVATE_PROPERTY_OFFSET
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_11_PROLOG
#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_RPC_WRAPPERS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_INCLASS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_PRIVATE_PROPERTY_OFFSET \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_INCLASS_NO_PURE_DECLS \
	UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealPlugin_PCG_Plugins_InfiniteVoxelWorld_Source_InfiniteVoxelWorld_Public_IVW_PlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

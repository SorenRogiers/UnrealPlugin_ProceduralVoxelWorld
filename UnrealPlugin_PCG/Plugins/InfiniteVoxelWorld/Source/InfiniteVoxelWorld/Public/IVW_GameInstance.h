// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IVW_GameInstance.generated.h"

USTRUCT(BlueprintType)
struct FSaveData
{
	GENERATED_USTRUCT_BODY()
	FSaveData(FString saveName = "", FDateTime saveTime = FDateTime()) : SaveName(saveName), SaveTime(saveTime) {}

	UPROPERTY(BlueprintReadWrite)
	FString SaveName;

	UPROPERTY(BlueprintReadWrite)
	FDateTime SaveTime;
};

UCLASS()
class INFINITEVOXELWORLD_API UIVW_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RandomSeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SeedName;

	UFUNCTION(BlueprintCallable, Category = TDLHelpers)
	TArray<FSaveData> GetAllSaveGameSlotNames();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameName;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IVW_GameInstance.generated.h"

UCLASS()
class INFINITEVOXELWORLD_API UIVW_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RandomSeed = 0;

};

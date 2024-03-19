// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularGameState.h"
#include "LjtGameState.generated.h"

/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtGameState : public AModularGameStateBase
{
	GENERATED_BODY()

public:
	ALjtGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};

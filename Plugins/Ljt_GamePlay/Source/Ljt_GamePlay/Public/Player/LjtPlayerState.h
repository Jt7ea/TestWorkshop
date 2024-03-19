// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularPlayerState.h"
#include "LjtPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtPlayerState : public AModularPlayerState
{
	GENERATED_BODY()

public:
	ALjtPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};

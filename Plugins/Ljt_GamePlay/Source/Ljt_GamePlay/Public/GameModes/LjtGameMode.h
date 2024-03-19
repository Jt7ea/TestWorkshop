// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularGameMode.h"
#include "LjtGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtGameMode : public AModularGameModeBase
{
	GENERATED_BODY()
	
public:
	ALjtGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

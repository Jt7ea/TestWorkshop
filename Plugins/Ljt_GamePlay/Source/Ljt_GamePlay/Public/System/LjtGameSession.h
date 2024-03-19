// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "LjtGameSession.generated.h"

/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtGameSession : public AGameSession
{
	GENERATED_BODY()

public:

	ALjtGameSession(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};

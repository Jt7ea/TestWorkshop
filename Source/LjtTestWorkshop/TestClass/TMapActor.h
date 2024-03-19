// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LjtTestWorkshop/MyTestBase/MyTestActor.h"
#include "TMapActor.generated.h"

/**
 * 
 */
UCLASS()
class LJTTESTWORKSHOP_API ATMapActor : public AMyTestActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TMap<int32, int32> myIntMap;

public:
	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void FillMap();

	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void PrintMap();
	
};

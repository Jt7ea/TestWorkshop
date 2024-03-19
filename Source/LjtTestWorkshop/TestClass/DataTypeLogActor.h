// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LjtTestWorkshop/MyTestBase/MyTestActor.h"
#include "DataTypeLogActor.generated.h"

/**
 * 
 */
UCLASS()
class LJTTESTWORKSHOP_API ADataTypeLogActor : public AMyTestActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void PrintDataTypeLog();
};

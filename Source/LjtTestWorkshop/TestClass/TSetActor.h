// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LjtTestWorkshop/MyTestBase/MyTestActor.h"
#include "TSetActor.generated.h"

/**
 * 
 */
UCLASS()
class LJTTESTWORKSHOP_API ATSetActor : public AMyTestActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TSet<FString> myStringSet;

	UPROPERTY()
		TSet<FString> testSortSet = { TEXT("A"),TEXT("AA"),TEXT("AAA"),TEXT("AAAA") };

public:
	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void FillTSet();


	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void FindElementFromTSet();

	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		void SortTSet();
};

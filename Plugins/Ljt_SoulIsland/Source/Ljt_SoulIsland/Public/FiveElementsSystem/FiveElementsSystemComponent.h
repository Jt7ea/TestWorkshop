// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SoulIslandActorComponent.h"
#include "Blueprint\UserWidget.h"
#include "FiveElementsSystemComponent.generated.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class FiveElementsType: uint8 {
	Metals,
	Fire,
	Timber,
	Water,
	Soil
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LJT_SOULISLAND_API UFiveElementsSystemComponent : public USoulIslandActorComponent
{
	GENERATED_BODY()

public:
	UFiveElementsSystemComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "FiveElementsSystem")
		FiveElementsType GetFiveElements();

	UFUNCTION(BlueprintCallable, Category = "FiveElementsSystem")
		void RandomFiveElementsType();

	UFUNCTION(BlueprintCallable, Category = "FiveElementsSystem")
		void SetFiveElements(FiveElementsType elementsType);
	
private:
	UPROPERTY(VisibleAnywhere, Category = "FiveElementsSystem")
		FiveElementsType fiveElements;

	UPROPERTY()
		TArray<FiveElementsType> randomElementsArr;
};

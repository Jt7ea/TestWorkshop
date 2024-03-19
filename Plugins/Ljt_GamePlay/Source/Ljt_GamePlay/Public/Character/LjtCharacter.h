// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "LjtPawnData.h"
#include "LjtCharacter.generated.h"


/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtCharacter : public AModularCharacter
{
	GENERATED_BODY()
public:
	ALjtCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Character")
		void InitPawnData();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
		TObjectPtr<ULjtPawnData> PawnData;
};

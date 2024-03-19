// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LjtPlayerController.h"
#include "TopDownControllerData.h"
#include "LjtTopDownPlayerController.generated.h"

class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtTopDownPlayerController : public ALjtPlayerController
{
	GENERATED_BODY()
	
public:
	ALjtTopDownPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UTopDownControllerData* ControllerData;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();

};

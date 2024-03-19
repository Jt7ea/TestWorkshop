// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LjtPlayerController.h"

ALjtPlayerController::ALjtPlayerController(const FObjectInitializer& ObjectInitializer)
{
}

void ALjtPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();
}

void ALjtPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
}

void ALjtPlayerController::OnPossess(APawn* APawn)
{
	Super::OnPossess(APawn);
}

void ALjtPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

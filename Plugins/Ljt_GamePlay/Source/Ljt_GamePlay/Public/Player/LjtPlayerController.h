// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonPlayerController.h"
#include "LjtPlayerController.generated.h"

/**
 *
 */
UCLASS()
class LJT_GAMEPLAY_API ALjtPlayerController : public ACommonPlayerController
{
	GENERATED_BODY()


public:
	ALjtPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void ReceivedPlayer() override;
	virtual void SetPawn(APawn* InPawn) override;
	virtual void OnPossess(class APawn* APawn) override;
	virtual void OnUnPossess() override;
};


UCLASS()
class ALjtReplayPlayerController : public ALjtPlayerController
{
	GENERATED_BODY()


	//virtual void Tick(float DeltaSeconds) override;
	//virtual void SmoothTargetViewRotation(APawn* TargetPawn, float DeltaSeconds) override;
	//virtual bool ShouldRecordClientReplay() override;

	//// Callback for when the game state's RecorderPlayerState gets replicated during replay playback
	//void RecorderPlayerStateUpdated(APlayerState* NewRecorderPlayerState);

	//// Callback for when the followed player state changes pawn
	//UFUNCTION()
	//	void OnPlayerStatePawnSet(APlayerState* ChangedPlayerState, APawn* NewPlayerPawn, APawn* OldPlayerPawn);

	//// The player state we are currently following */
	//UPROPERTY(Transient)
	//	TObjectPtr<APlayerState> FollowedPlayerState;

};
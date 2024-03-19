// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/LjtGameMode.h"

ALjtGameMode::ALjtGameMode(const FObjectInitializer& ObjectInitializer)
{
	GameStateClass = ALjtGameState::StaticClass();
	GameSessionClass = ALjtGameSession::StaticClass();
	PlayerControllerClass = ALjtPlayerController::StaticClass();
	ReplaySpectatorPlayerControllerClass = ALjtReplayPlayerController::StaticClass();
	PlayerStateClass = ALjtPlayerState::StaticClass();
	DefaultPawnClass = ALjtCharacter::StaticClass();
	//HUDClass = AHUD::StaticClass();
}

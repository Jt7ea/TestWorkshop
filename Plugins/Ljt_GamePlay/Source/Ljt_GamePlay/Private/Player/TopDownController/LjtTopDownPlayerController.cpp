// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopDownController/LjtTopDownPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Blueprint\AIBlueprintHelperLibrary.h"
#include "NiagaraFunctionLibrary.h"
//#include "NiagaraFunctionLibrary.h"
//#include "E:\UE_5.3\Engine\Plugins\FX\Niagara\Source\Niagara\Public\NiagaraFunctionLibrary.h"
//E:\UE_5.3\Engine\Plugins\FX\Niagara\Source\Niagara\Public\NiagaraFunctionLibrary.h
//E:\UE_5.3\Engine\Source\Runtime\AIModule\Classes\Blueprint\AIBlueprintHelperLibrary.h
ALjtTopDownPlayerController::ALjtTopDownPlayerController()
{
	//基础设置
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ALjtTopDownPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(ControllerData)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ControllerData is Null")));
		return;
	}
	//初始化变量
	ControllerData->CachedDestination=FVector::ZeroVector;
	ControllerData->FollowTime = 0.f;

	//增强输入
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(ControllerData->DefaultMappingContext, 0);
	}
}

void ALjtTopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//设置输入绑定
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		//设置鼠标输入事件
		EnhancedInputComponent->BindAction(ControllerData->SetDestinationClickAction, ETriggerEvent::Started, this, &ALjtTopDownPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(ControllerData->SetDestinationClickAction, ETriggerEvent::Triggered, this, &ALjtTopDownPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(ControllerData->SetDestinationClickAction, ETriggerEvent::Completed, this, &ALjtTopDownPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(ControllerData->SetDestinationClickAction, ETriggerEvent::Canceled, this, &ALjtTopDownPlayerController::OnSetDestinationReleased);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("EnhancedInput Module Not Found")));
	}
}

void ALjtTopDownPlayerController::OnInputStarted()
{
	StopMovement();
}

void ALjtTopDownPlayerController::OnSetDestinationTriggered()
{
	ControllerData->FollowTime += GetWorld()->GetDeltaSeconds();

	//寻找玩家在游戏世界中按下输入的位置
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	//如果碰到地面，就把位置存起来
	if (bHitSuccessful)
	{
		ControllerData->CachedDestination = Hit.Location;
	}

	//移动到鼠标点击处
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (ControllerData->CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void ALjtTopDownPlayerController::OnSetDestinationReleased()
{
	//判断是否为单击
	if (ControllerData->FollowTime <= ControllerData->ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, ControllerData->CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ControllerData->FXCursor, ControllerData->CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
	ControllerData->FollowTime = 0.f;
}

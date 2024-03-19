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
	//��������
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
	//��ʼ������
	ControllerData->CachedDestination=FVector::ZeroVector;
	ControllerData->FollowTime = 0.f;

	//��ǿ����
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(ControllerData->DefaultMappingContext, 0);
	}
}

void ALjtTopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//���������
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		//������������¼�
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

	//Ѱ���������Ϸ�����а��������λ��
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	//����������棬�Ͱ�λ�ô�����
	if (bHitSuccessful)
	{
		ControllerData->CachedDestination = Hit.Location;
	}

	//�ƶ����������
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (ControllerData->CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void ALjtTopDownPlayerController::OnSetDestinationReleased()
{
	//�ж��Ƿ�Ϊ����
	if (ControllerData->FollowTime <= ControllerData->ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, ControllerData->CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ControllerData->FXCursor, ControllerData->CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
	ControllerData->FollowTime = 0.f;
}

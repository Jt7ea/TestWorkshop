// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LjtCharacter.h"

ALjtCharacter::ALjtCharacter(const FObjectInitializer& ObjectInitializer)
{
}

void ALjtCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitPawnData();
}

void ALjtCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ALjtCharacter::InitPawnData()
{
	if (!IsValid(PawnData)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ALjtCharacter PawnData is Null")));
		return;
	}

	if (!IsValid(PawnData->SkeletalMeshAsset)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ALjtCharacter PawnData->SkeletalMeshAsset is Null")));
		return;
	}
	USkeletalMeshComponent* mySkeletalMeshComponent = GetMesh();
	mySkeletalMeshComponent->SetSkeletalMeshAsset(PawnData->SkeletalMeshAsset);
	mySkeletalMeshComponent->SetAnimInstanceClass(PawnData->AnimClass);

}

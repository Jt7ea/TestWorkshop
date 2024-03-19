// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/LjtActivatableWidget.h"
#include "LjtHUDLayout.generated.h"

/**
 *
 */
UCLASS()
class LJT_GAMEPLAY_API ULjtHUDLayout : public ULjtActivatableWidget
{
	GENERATED_BODY()
public:
	ULjtHUDLayout(const FObjectInitializer& ObjectInitializer);

	void NativeOnInitialized() override;

protected:
	void HandleEscapeAction();

	UPROPERTY(EditDefaultsOnly)
		TSoftClassPtr<UCommonActivatableWidget> EscapeMenuClass;
};

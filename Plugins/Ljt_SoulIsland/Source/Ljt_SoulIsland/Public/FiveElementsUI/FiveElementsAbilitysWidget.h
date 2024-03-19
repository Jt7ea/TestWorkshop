// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components\Image.h"
#include "FiveElementsAbilitysWidget.generated.h"
/**
 * 
 */
UCLASS()
class LJT_SOULISLAND_API UFiveElementsAbilitysWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
		UImage* AbilityBox1;
	UPROPERTY(meta = (BindWidget))
		UImage* AbilityBox2;
	UPROPERTY(meta = (BindWidget))
		UImage* AbilityBox3;
	UPROPERTY(meta = (BindWidget))
		UImage* AbilityBox4;


	virtual bool Initialize() override;
	
};

// Fill out your copyright notice in the Description page of Project Settings.



#include "UI/LjtHUDLayout.h"
#include "Input/CommonUIInputTypes.h"
#include "GameplayTagsModule.h"
#include "CommonUIExtensions.h"

ULjtHUDLayout::ULjtHUDLayout(const FObjectInitializer& ObjectInitializer)
{

}
void ULjtHUDLayout::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	FGameplayTag tag = FGameplayTag::RequestGameplayTag("UI.Action.Escape");
	RegisterUIActionBinding(FBindUIActionArgs(FUIActionTag::ConvertChecked(tag), false, FSimpleDelegate::CreateUObject(this, &ThisClass::HandleEscapeAction)));
}

void ULjtHUDLayout::HandleEscapeAction()
{
	if (ensure(!EscapeMenuClass.IsNull()))
	{
		FGameplayTag tag = FGameplayTag::RequestGameplayTag("UI.Layer.Menu");
		UCommonUIExtensions::PushStreamedContentToLayer_ForPlayer(GetOwningLocalPlayer(), tag, EscapeMenuClass);
	}
}

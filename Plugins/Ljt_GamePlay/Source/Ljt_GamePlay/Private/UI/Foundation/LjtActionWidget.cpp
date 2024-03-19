// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Foundation/LjtActionWidget.h"
#include "EnhancedInputSubsystems.h"
#include "CommonInputBaseTypes.h"
#include "Engine/LocalPlayer.h"
#include "CommonInputSubsystem.h"

FSlateBrush ULjtActionWidget::GetIcon() const
{
	if (AssociatedInputAction)
	{
		UCommonInputSubsystem* CommonInputSubsystem = GetInputSubsystem();
		UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = GetEnhancedInputSubsystem();
		TArray<FKey> BoundKeys = EnhancedInputSubsystem->QueryKeysMappedToAction(AssociatedInputAction);
		FSlateBrush SlateBrush;

		if (!BoundKeys.IsEmpty() && UCommonInputPlatformSettings::Get()->TryGetInputBrush(SlateBrush, BoundKeys[0], CommonInputSubsystem->GetCurrentInputType(), CommonInputSubsystem->GetCurrentGamepadName()))
		{
			return SlateBrush;
		}
	}

	return Super::GetIcon();
}

UEnhancedInputLocalPlayerSubsystem* ULjtActionWidget::GetEnhancedInputSubsystem() const
{
	const UWidget* BoundWidget = DisplayedBindingHandle.GetBoundWidget();
	const ULocalPlayer* BindingOwner = BoundWidget ? BoundWidget->GetOwningLocalPlayer() : GetOwningLocalPlayer();

	return BindingOwner->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
}

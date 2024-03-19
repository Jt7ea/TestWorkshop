// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LjtActivatableWidget.h"

ULjtActivatableWidget::ULjtActivatableWidget(const FObjectInitializer& ObjectInitializer)
{
	
}

TOptional<FUIInputConfig> ULjtActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case ELjtWidgetInputMode::GameAndMenu:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
	case ELjtWidgetInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
	case ELjtWidgetInputMode::Menu:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
	case ELjtWidgetInputMode::Default:
	default:
		return TOptional<FUIInputConfig>();
	}
}

#if WITH_EDITOR
void ULjtActivatableWidget::ValidateCompiledWidgetTree(const UWidgetTree& BlueprintWidgetTree, IWidgetCompilerLog& CompileLog) const
{

}
#endif

#undef LOCTEXT_NAMESPACE
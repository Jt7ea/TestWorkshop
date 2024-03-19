// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "LjtActivatableWidget.generated.h"

/**
 * 
 */
struct FUIInputConfig;

UENUM(BlueprintType)
enum class ELjtWidgetInputMode : uint8
{
	Default,
	GameAndMenu,
	Game,
	Menu
};

UCLASS(Abstract, Blueprintable)
class LJT_GAMEPLAY_API ULjtActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
		ULjtActivatableWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	//~UCommonActivatableWidget interface
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	//~End of UCommonActivatableWidget interface

#if WITH_EDITOR
	virtual void ValidateCompiledWidgetTree(const UWidgetTree& BlueprintWidgetTree, class IWidgetCompilerLog& CompileLog) const override;
#endif

protected:
	/** The desired input mode to use while this UI is activated, for example do you want key presses to still reach the game/player controller? */
	UPROPERTY(EditDefaultsOnly, Category = Input)
		ELjtWidgetInputMode InputConfig = ELjtWidgetInputMode::Default;

	/** The desired mouse behavior when the game gets input. */
	UPROPERTY(EditDefaultsOnly, Category = Input)
		EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};

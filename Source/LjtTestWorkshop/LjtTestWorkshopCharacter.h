// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "..\..\Plugins\Ljt_SoulIsland\Source\Ljt_SoulIsland\Public\FiveElementsSystem\FiveElementsSystemComponent.h"
#include "LjtTestWorkshopCharacter.generated.h"

UCLASS(Blueprintable)
class ALjtTestWorkshopCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALjtTestWorkshopCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HealthComponent")
		UWidgetComponent* myHealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FiveElementsComponent")
		UFiveElementsSystemComponent* fiveElementsSystemComponent;
};


// Fill out your copyright notice in the Description page of Project Settings.


#include "FiveElementsSystem/FiveElementsSystemComponent.h"

UFiveElementsSystemComponent::UFiveElementsSystemComponent()
{
	randomElementsArr.Empty();
	FiveElementsType metals = FiveElementsType::Metals;
	FiveElementsType fire = FiveElementsType::Fire;
	FiveElementsType timber = FiveElementsType::Timber;
	FiveElementsType water = FiveElementsType::Water;
	FiveElementsType soil = FiveElementsType::Soil;
	randomElementsArr.Add(metals);
	randomElementsArr.Add(fire);
	randomElementsArr.Add(timber);
	randomElementsArr.Add(water);
	randomElementsArr.Add(soil);
	RandomFiveElementsType();
}

void UFiveElementsSystemComponent::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("This is : UFiveElementsSystemComponent::BeginPlay"));

	UClass* widgetClass = LoadClass<UUserWidget>(NULL, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BPClass/UI/BP_FiveElementsAbilitysWidget.BP_FiveElementsAbilitysWidget_C'"));

	UUserWidget* myWidgetClass = nullptr;
	myWidgetClass = CreateWidget<UUserWidget>(GetWorld(), widgetClass);

	myWidgetClass->AddToViewport();
}

FiveElementsType UFiveElementsSystemComponent::GetFiveElements()
{
	return fiveElements;
}

void UFiveElementsSystemComponent::RandomFiveElementsType()
{
	int32 RandomInt = FMath::RandRange(0,4);
	fiveElements = randomElementsArr[RandomInt];
}

void UFiveElementsSystemComponent::SetFiveElements(FiveElementsType elementsType)
{
	fiveElements = elementsType;
}

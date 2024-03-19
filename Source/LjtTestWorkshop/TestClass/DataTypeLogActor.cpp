// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTypeLogActor.h"

void ADataTypeLogActor::PrintDataTypeLog()
{
	int32 myInt = 10;
	float myFloat = 5.0f;
	bool myBool = true;
	char myChar = 'A';
	FString myString = TEXT("MyString");
	FVector myVector = FVector(0, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("%d"), myInt);
	UE_LOG(LogTemp, Warning, TEXT("%f"), myFloat);
	UE_LOG(LogTemp, Warning, TEXT("%d"), myBool);
	UE_LOG(LogTemp, Warning, TEXT("%c"), myChar);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *myString);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *myVector.ToString());
}

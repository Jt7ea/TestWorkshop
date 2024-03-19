// Fill out your copyright notice in the Description page of Project Settings.


#include "TMapActor.h"

void ATMapActor::FillMap()
{
	myIntMap.Emplace(0,1);
	myIntMap.Emplace(1,2);
	myIntMap.Emplace(2,3);
	myIntMap.Emplace(3,4);
	myIntMap.Emplace(4,5);
}

void ATMapActor::PrintMap()
{
	for (auto& tempMap:myIntMap) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Key: %d" "Value: %d"), tempMap.Key, tempMap.Value));
	}
}

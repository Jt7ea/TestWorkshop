// Fill out your copyright notice in the Description page of Project Settings.


#include "TSetActor.h"

void ATSetActor::FillTSet()
{
	myStringSet.Add(TEXT("Hello"));
	myStringSet.Add(TEXT("World"));
	myStringSet.Emplace(TEXT("!"));
}

void ATSetActor::FindElementFromTSet()
{
	FString* isFind = myStringSet.Find(TEXT("World"));

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("isFind: %s"), isFind));
}

void ATSetActor::SortTSet()
{
	for (auto It = testSortSet.CreateConstIterator(); It; ++It) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *It);
	}

	testSortSet.Sort([](FString A, FString B) {
		return A.Len() > B.Len();
	});

	for (auto It = testSortSet.CreateConstIterator(); It; ++It) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,*It);
	}
}

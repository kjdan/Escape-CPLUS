// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterClass.h"

/**
 * 
 */
class MAINENGINEER_API MyBuildingClass
{
public:



	int level;
	FString name;
	MyCharacterClass* firstWorker;
	MyCharacterClass* secondWorker;

	MyBuildingClass(int level,FString name, MyCharacterClass* firstWorker,MyCharacterClass* secondWorker);
	~MyBuildingClass();
};

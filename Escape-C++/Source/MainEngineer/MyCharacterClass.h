// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

/**
 * 
 */
class MAINENGINEER_API MyCharacterClass
{
public:

	
	UENUM(EditAnywhere,BlueprintReadWrite,Category = Enum)
		enum Job
	{
		Cook,
		Fight,
		Build,
		Collect,
		CollectWater,
		Nothing
	};

	bool working;
	int cooking;
	int fighting;
	int collecting;
	int waterCollecting;
	FString name;
	Job myJob;
	MyCharacterClass* self;
	MyCharacterClass(bool working_, int cooking_,int fighting_,int collecting_, int waterCollecting_,FString name_);
	~MyCharacterClass();
};

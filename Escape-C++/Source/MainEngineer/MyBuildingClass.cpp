// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBuildingClass.h"

MyBuildingClass::MyBuildingClass(int level_, FString name_, MyCharacterClass* firstWorker_, MyCharacterClass* secondWorker_)
{
	level = level_;
	name = name_;
	firstWorker = firstWorker_;
	secondWorker = secondWorker_;
}

MyBuildingClass::~MyBuildingClass()
{
}

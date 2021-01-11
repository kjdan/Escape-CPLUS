// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterClass.h"


MyCharacterClass::MyCharacterClass(bool working_, int cooking_, int fighting_,  int collecting_, int waterCollecting_,FString name_)
{
	working = working_;
	cooking = cooking_;
	fighting = fighting_;
	collecting = collecting_;
	waterCollecting = waterCollecting_;
	name = name_;
	myJob = Nothing;
	self = this;
}

MyCharacterClass::~MyCharacterClass()
{
}

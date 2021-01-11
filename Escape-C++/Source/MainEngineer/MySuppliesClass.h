// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MAINENGINEER_API MySuppliesClass
{
public:
	MySuppliesClass(int water,int food,int wood);
	~MySuppliesClass();
	int water;
	int food;
	int wood;
};

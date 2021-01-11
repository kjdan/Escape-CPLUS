// Fill out your copyright notice in the Description page of Project Settings.

#include "Creator.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine.h"
#include "AllowWindowsPlatformTypes.h"
#include <WinSock2.h>
#include <sqlite3.h>
#include <HideWindowsPlatformTypes.h>


// Sets default values
ACreator::ACreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	actor = this;
	dayValue = 1;
	lightValue = 1;
	
}

// Called when the game starts or when spawned
void ACreator::BeginPlay()
{
	Super::BeginPlay();

	ACreator::createArrayOfBuildings();
	ACreator::createArrayOfCharacters();
	ACreator::createSuppliesObject();

}

// Called every frame
void ACreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACreator::createArrayOfCharacters()
{
	MyCharacterClass* pointer;
	FString tab[10] = { "Andrzej","Jarek","Piotr","Jacek","Krzysiek","Patryk","Marcel","Sebastian","Bartek","Marian" };
	for (int i = 0; i < 5; i++)
	{
		pointer = new MyCharacterClass(true, 1, 1, 1, 1,tab[i]);
		MyCharacters.Add(pointer);
	}
}

FString ACreator::sendFStringCharacter(int i)
{

	FString value = actor->MyCharacters[i]->name;
	return value;

}

FString ACreator::sendFStringBuilding(int i)
{

	FString value = actor->MyBuildings[i]->name;
	return value;

}

void ACreator::createArrayOfBuildings()
{
	MyBuildingClass* pointer;
	FString tab[5] = {"Kuchnia","Mur","Zbieralnia","Budowa","Wodociag"};
	for (int i = 0; i < 5; i++)
	{
		pointer = new MyBuildingClass(0,tab[i],NULL,NULL);
		MyBuildings.Add(pointer);
	}
}

ACreator * ACreator::createActor()
{

	UWorld* world = GetWorld();
	TActorIterator<ACreator> it(world, ACreator::StaticClass());
	ACreator* actor = *it;
	return *it;
}

void ACreator::whatObject(FString name)
{
	ACreator::nameOfCilckedObject = name;
}

FString ACreator::sendObjectName()
{
	return ACreator::nameOfCilckedObject;
}

void ACreator::goBack()
{
	UGameplayStatics::OpenLevel(this, "MainScene");
}

int ACreator::upgradeBuilding(FString nameOfBuildingToUpgrade)
{
	
	FString value; 
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name == nameOfBuildingToUpgrade)
		{
			if (nameOfBuildingToUpgrade!="Budowa")
			{
				if (actor->MySupplies->wood >= (100 * (actor->MyBuildings[i]->level) + 20))
				{
					actor->MySupplies->wood = actor->MySupplies->wood - (100 * (actor->MyBuildings[i]->level)+20);
					actor->MyBuildings[i]->level = actor->MyBuildings[i]->level + 1;
					return actor->MyBuildings[i]->level;
				}
			}
			else
			{
				if (actor->MyBuildings[i]->firstWorker != NULL)
				{
					//if (actor->MyBuildings[i]->secondWorker != NULL)
					//{
						if (actor->MySupplies->wood >= (100 * (actor->MyBuildings[i]->level) + 20))
						{
							actor->MySupplies->wood = actor->MySupplies->wood - (100 * (actor->MyBuildings[i]->level)+20);
							actor->MyBuildings[i]->level = actor->MyBuildings[i]->level + 1;
							return actor->MyBuildings[i]->level;
						}
					//}
				}
			}
			if (nameOfBuildingToUpgrade == "Budowa")
			{
				if (actor->MyBuildings[i]->level == 0)
				{
					if (actor->MySupplies->wood >= (100 * (actor->MyBuildings[i]->level) + 20))
					{
						actor->MySupplies->wood = actor->MySupplies->wood - (100 * (actor->MyBuildings[i]->level) + 20);
						actor->MyBuildings[i]->level = actor->MyBuildings[i]->level + 1;
						return actor->MyBuildings[i]->level;
					}

				}
			}
		}
		
	}
	return 0;
}

FString ACreator::characterToBuilding1(FString nameOfCharacter, FString nameOfBuilding)
{
	FString value = "no";
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name == nameOfBuilding)
		{
			for (int j = 0; j < 5; j++)
			{
				if (actor->MyCharacters[j]->name == nameOfCharacter)
				{
					if (actor->MyCharacters[j]->working == true)
					{
						if (nameOfBuilding=="Budowa")
						{
							helpEnum = MyCharacterClass::Build;
							actor->MyCharacters[j]->myJob = helpEnum;
							actor->MyBuildings[i]->firstWorker = actor->MyCharacters[j]->self;
							value = actor->MyCharacters[j]->name;
							actor->MyCharacters[j]->working = false;
							return value;
						}
						if (nameOfBuilding=="Kuchnia")
						{
							helpEnum = MyCharacterClass::Cook;
							actor->MyCharacters[j]->myJob = helpEnum;
							actor->MyBuildings[i]->firstWorker = actor->MyCharacters[j]->self;
							value = actor->MyCharacters[j]->name;
							actor->MyCharacters[j]->working = false;
							return value;
						}
						if (nameOfBuilding=="Mur")
						{
							helpEnum = MyCharacterClass::Fight;
							actor->MyCharacters[j]->myJob = helpEnum;
							actor->MyBuildings[i]->firstWorker = actor->MyCharacters[j]->self;
							value = actor->MyCharacters[j]->name;
							actor->MyCharacters[j]->working = false;
							return value;
						}
						if (nameOfBuilding =="Wodociag")
						{
							helpEnum = MyCharacterClass::CollectWater;
							actor->MyCharacters[j]->myJob = helpEnum;
							actor->MyBuildings[i]->firstWorker = actor->MyCharacters[j]->self;
							value = actor->MyCharacters[j]->name;
							actor->MyCharacters[j]->working = false;
							return value;
						}
						if (nameOfBuilding =="Zbieralnia")
						{
							helpEnum = MyCharacterClass::Collect;
							actor->MyCharacters[j]->myJob = helpEnum;
							actor->MyBuildings[i]->firstWorker = actor->MyCharacters[j]->self;
							value = actor->MyCharacters[j]->name;
							actor->MyCharacters[j]->working = false;
							return value;
						}
					}
					
				}
				
			}
		}
	

	}
	return value;
}

void ACreator::createSuppliesObject()
{
	MySupplies = new MySuppliesClass(100, 100, 100);
}

void ACreator::updateSupplies()
{
	int wooodSupplies=0;
	int foodSupplies = 0;
	int waterSupplies = 0;
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name == "Kuchnia")
		{
			if (actor->MyBuildings[i]->firstWorker != NULL)
			{
				foodSupplies = foodSupplies + 100*(actor->MyBuildings[i]->firstWorker->cooking);
			}
	
			foodSupplies = foodSupplies + 100 * (actor->MyBuildings[i]->level);
		}
		else if (actor->MyBuildings[i]->name == "Zbieralnia")
		{
			if (actor->MyBuildings[i]->firstWorker != NULL)
			{
				wooodSupplies = wooodSupplies + 100 * (actor->MyBuildings[i]->firstWorker->collecting);
			}
		
		}
		else if (actor->MyBuildings[i]->name == "Wodociag")
		{
			if (actor->MyBuildings[i]->firstWorker != NULL)
			{
				waterSupplies = waterSupplies + 100 * (actor->MyBuildings[i]->firstWorker->waterCollecting);
			}
		
		}
	}
	actor->MySupplies->food = actor->MySupplies->food + foodSupplies;
	actor->MySupplies->water = actor->MySupplies->water + waterSupplies;
	actor->MySupplies->wood = actor->MySupplies->wood + wooodSupplies;
}

int ACreator::showWood()
{
	return actor->MySupplies->wood;
}

int ACreator::showWater()
{
	return actor->MySupplies->water;
}

int ACreator::showFood()
{
	return actor->MySupplies->food;
}

void ACreator::nightTime()
{
	helpEnum = MyCharacterClass::Nothing;
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name != "Mur")
		{
			if (actor->MyBuildings[i]->name=="Zbieralnia")
			{
				if (actor->MyBuildings[i]->firstWorker != NULL)
				{
					actor->MyBuildings[i]->firstWorker->collecting = actor->MyBuildings[i]->firstWorker->collecting + 1;
					if ((actor->MySupplies->food-(dayValue*10))>0)
					{
						if ((actor->MySupplies->water - (dayValue * 10)) > 0)
						{
							actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
							actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
							actor->MyBuildings[i]->firstWorker->working = true;
							
						}
					}
					actor->MyBuildings[i]->firstWorker = NULL;
				}

			
			}


			if (actor->MyBuildings[i]->name == "Wodociag")
			{
				if (actor->MyBuildings[i]->firstWorker != NULL)
				{
					actor->MyBuildings[i]->firstWorker->waterCollecting = actor->MyBuildings[i]->firstWorker->waterCollecting + 1;
					if ((actor->MySupplies->food - (dayValue * 10)) > 0)
					{
						if ((actor->MySupplies->water - (dayValue * 10)) > 0)
						{
							actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
							actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
							actor->MyBuildings[i]->firstWorker->working = true;
							
						}
					}
					actor->MyBuildings[i]->firstWorker = NULL;
				}

			
			}


			if (actor->MyBuildings[i]->name == "Kuchnia")
			{
				if (actor->MyBuildings[i]->firstWorker != NULL)
				{
					actor->MyBuildings[i]->firstWorker->cooking = actor->MyBuildings[i]->firstWorker->cooking + 1;
					if ((actor->MySupplies->food - (dayValue * 10)) > 0)
					{
						if ((actor->MySupplies->water - (dayValue * 10)) > 0)
						{
							actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
							actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
							actor->MyBuildings[i]->firstWorker->working = true;
							
						}
					}
					actor->MyBuildings[i]->firstWorker = NULL;
				}

				
			}

			if (actor->MyBuildings[i]->name == "Budowa")
			{
				if (actor->MyBuildings[i]->firstWorker != NULL)
				{
					
					if ((actor->MySupplies->food - (dayValue * 10)) > 0)
					{
						if ((actor->MySupplies->water - (dayValue * 10)) > 0)
						{
							actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
							actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
							actor->MyBuildings[i]->firstWorker->working = true;
							
						}
					}
					actor->MyBuildings[i]->firstWorker = NULL;
				}

			
			}
		}
		

	}
	
	for (int j = 0; j < 5; j++)
	{
		helpEnum = MyCharacterClass::Nothing;
		if (actor->MyCharacters[j]->myJob==helpEnum)
		{
			actor->MyCharacters[j]->working = false;
			if ((actor->MySupplies->food - (dayValue * 10)) > 0)
			{
				if ((actor->MySupplies->water - (dayValue * 10)) > 0)
				{
					actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
					actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
					actor->MyCharacters[j]->working = true;
				}
			}

		}
		else
		{
			helpEnum = MyCharacterClass::Fight;
			if (actor->MyCharacters[j]->myJob != helpEnum)
			{
				helpEnum = MyCharacterClass::Nothing;
				actor->MyCharacters[j]->myJob = helpEnum;
			}
		}
	}
}

FString ACreator::sendFirstCharacter(FString nameOfBuilding)
{
	FString value = "";
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name == nameOfBuilding)
		{
			if (actor->MyBuildings[i]->firstWorker != NULL)
			{
				value = actor->MyBuildings[i]->firstWorker->name;
				return value;
			}
		}

	}
	return value;
}

int ACreator::sendUpgradeLevel(FString nameOfBuilding)
{
	int value=0;
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name==nameOfBuilding)
		{
			value = actor->MyBuildings[i]->level;
			return value;
		}
	}
	return value;
}

int ACreator::gameStatus()
{
	int value = 0;
	int valueToReturn = 0;
	helpEnum = MyCharacterClass::Nothing;
	for (int i= 0; i < 5; i++)
	{
		if (actor->MyBuildings[i]->name == "Mur")
		{
			if (actor->MyBuildings[i]->firstWorker != NULL)
			{
				

				actor->MyBuildings[i]->firstWorker->fighting = actor->MyBuildings[i]->firstWorker->fighting + 1;
				if ((actor->MySupplies->food - (dayValue * 10)) > 0)
				{
					if ((actor->MySupplies->water - (dayValue * 10)) > 0)
					{
						actor->MySupplies->water = actor->MySupplies->water - (dayValue * 10);
						actor->MySupplies->food = actor->MySupplies->food - (dayValue * 10);
						value = value + (actor->MyBuildings[i]->firstWorker->fighting);
						actor->MyBuildings[i]->firstWorker->myJob = helpEnum;
					}
				}
				actor->MyBuildings[i]->firstWorker = NULL;
			}
			value = value + 10 * (actor->MyBuildings[i]->level);

		}






		
	}
	
	
	
		for (int j = 0; j < 5; j++)
		{
			if (actor->MyBuildings[j]->name == "Budowa")
			{
				if ((actor->dayValue) * 2 > value)
				{
					actor->MyBuildings[j]->level = actor->MyBuildings[j]->level - 5;
				}


				actor->dayValue = actor->dayValue + 1;


				if (actor->MyBuildings[j]->level >= 0)
				{
					if (actor->MyBuildings[j]->level >= 15)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return -1;
				}

			}
				
		}
	

	
	return 0;
}

int ACreator::getCooking(FString nameOfCharacter)
{
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyCharacters[i]->name == nameOfCharacter)
		{
			return actor->MyCharacters[i]->cooking;
		}
	}
	return 0;
}

int ACreator::getFighting(FString nameOfCharacter)
{
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyCharacters[i]->name == nameOfCharacter)
		{
			return actor->MyCharacters[i]->fighting;
		}
	}
	return 0;
}

int ACreator::getCollecting(FString nameOfCharacter)
{
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyCharacters[i]->name == nameOfCharacter)
		{
			return actor->MyCharacters[i]->collecting;
		}
	}
	return 0;
}

int ACreator::getCollectingWater(FString nameOfCharacter)
{
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyCharacters[i]->name == nameOfCharacter)
		{
			return actor->MyCharacters[i]->waterCollecting;
		}
	}
	return 0;
}

bool ACreator::getWorking(FString nameOfCharacter)
{
	for (int i = 0; i < 5; i++)
	{
		if (actor->MyCharacters[i]->name == nameOfCharacter)
		{
			return actor->MyCharacters[i]->working;
		}
	}
	return true;
}

int ACreator::getLightValue()
{
	return actor->lightValue;
}

void ACreator::setLightValue(int value)
{
	actor->lightValue = value;
	
}

void ACreator::loadActor(ACreator * savedActor)
{
	actor->lightValue = savedActor->lightValue;
	actor->dayValue = savedActor->dayValue;
	actor->MySupplies->food = savedActor->MySupplies->food;
	actor->MySupplies->wood = savedActor->MySupplies->wood;
	actor->MySupplies->water = savedActor->MySupplies->water;
	for (int i = 0; i < 5; i++)
	{
		actor->MyCharacters[i]->collecting = savedActor->MyCharacters[i]->collecting;
		actor->MyCharacters[i]->waterCollecting = savedActor->MyCharacters[i]->waterCollecting;
		actor->MyCharacters[i]->cooking = savedActor->MyCharacters[i]->cooking;
		actor->MyCharacters[i]->myJob = savedActor->MyCharacters[i]->myJob;
		actor->MyCharacters[i]->working = savedActor->MyCharacters[i]->working;
		actor->MyCharacters[i]->fighting = savedActor->MyCharacters[i]->fighting;
		actor->MyCharacters[i]->self = savedActor->MyCharacters[i]->self;
		actor->MyBuildings[i]->firstWorker = savedActor->MyBuildings[i]->firstWorker;
		actor->MyBuildings[i]->level = savedActor->MyBuildings[i]->level;
	}
}

TArray<int> ACreator::getArrayOfLevelBuildings()
{
	TArray<int> levelOfBuildings;
	for (int i = 0; i < 5; i++)
	{
		levelOfBuildings.Add(actor->MyBuildings[i]->level);
	}

	return levelOfBuildings;
}

void ACreator::setArrayOfLevelBuildings(TArray<int> listOfLevel)
{
	for (int i = 0; i < 5; i++)
	{
		actor->MyBuildings[i]->level = listOfLevel[i];
	}
}

TArray<int> ACreator::getArrayOfOthers()
{
	TArray<int> listOfOthers;
	listOfOthers.Add(actor->lightValue);
	listOfOthers.Add(actor->dayValue);
	listOfOthers.Add(actor->MySupplies->food);
	listOfOthers.Add(actor->MySupplies->wood);
	listOfOthers.Add(actor->MySupplies->water);

	return listOfOthers;
}

void ACreator::setArrayOfOthers(TArray<int> listOfOthers)
{
	actor->lightValue = listOfOthers[0];
	actor->dayValue = listOfOthers[1];
	actor->MySupplies->food = listOfOthers[2];
	actor->MySupplies->wood = listOfOthers[3];
	actor->MySupplies->water = listOfOthers[4];

}

TArray<int> ACreator::getArrayOfCollecting()
{
	TArray<int> listOfCollecting;
	for (int i = 0; i < 5; i++)
	{
		listOfCollecting.Add(actor->MyCharacters[i]->collecting);
	}
	return listOfCollecting;
}

void ACreator::setArrayOfCollecting(TArray<int> listOfCollecting)
{
	for (int i = 0; i < 5; i++)
	{
		actor->MyCharacters[i]->collecting = listOfCollecting[i];
		actor->MyCharacters[i]->working = true;
	}

}

TArray<int> ACreator::getArrayOfWaterCollecting()
{
	TArray<int> listOfWaterCollecting;
	for (int i = 0; i < 5; i++)
	{
		listOfWaterCollecting.Add(actor->MyCharacters[i]->waterCollecting);
	}
	return listOfWaterCollecting;
}

void ACreator::setArrayOfWaterCollecting(TArray<int> listOfWaterCollecting)
{
	for (int i = 0; i < 5; i++)
	{
		actor->MyCharacters[i]->waterCollecting = listOfWaterCollecting[i];
	}
}

TArray<int> ACreator::getArrayOfCooking()
{
	TArray<int> listOfCooking;
	for (int i = 0; i < 5; i++)
	{
		listOfCooking.Add(actor->MyCharacters[i]->cooking);
	}
	return listOfCooking;
}

void ACreator::setArrayOfCooking(TArray<int> listOfCooking)
{
	for (int i = 0; i < 5; i++)
	{
		actor->MyCharacters[i]->cooking = listOfCooking[i];
	}
}

TArray<int> ACreator::getArrayOfFighting()
{
	TArray<int> listOfFighting;
	for (int i = 0; i < 5; i++)
	{
		listOfFighting.Add(actor->MyCharacters[i]->fighting);
	}
	return listOfFighting;
}

void ACreator::setArrayOfFighting(TArray<int> listOfFighting)
{
	for (int i = 0; i < 5; i++)
	{
		actor->MyCharacters[i]->fighting = listOfFighting[i];
	}
}

int ACreator::startConnection()
{
	int i = 0;
	//MyDataBaseClass mdbs;
	//int i=mdbs.LoadBuildingFromData();
	return i;
}

FString ACreator::getName()
{
	
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	FString ok = "blad";


	rc = sqlite3_open("test.db", &db);

	if (rc) {
		
		return ok;
	}
	else {
		ok = "ok";
		rc = sqlite3_exec(db, "Select* from User;", 0, 0, &zErrMsg);
		
		if (rc != SQLITE_OK) {
			ok = sqlite3_errmsg(db);
			sqlite3_free(zErrMsg);
			return ok;
		}
		else {
			ok = "super ok";
		}
		sqlite3_close(db);
		return ok;
	}
	
}


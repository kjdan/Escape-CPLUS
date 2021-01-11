// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyCharacterClass.h"
#include "MyBuildingClass.h"
#include "MySuppliesClass.h"
//#include "MyDataBaseClass.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Creator.generated.h"

UCLASS()
class MAINENGINEER_API ACreator : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ACreator* actor;
	ACreator();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
		  TArray<MyCharacterClass*> MyCharacters;

		  TArray<MyBuildingClass*> MyBuildings;
		  MySuppliesClass* MySupplies;
		   TArray<UStaticMeshComponent*>Meshes;
		 FString nameOfCilckedObject;
		 int dayValue;
		 MyCharacterClass::Job helpEnum;
		 int lightValue;

		 UFUNCTION(BlueprintCallable)
			 void createArrayOfCharacters();
		 UFUNCTION(BlueprintCallable)
			 FString sendFStringCharacter(int i);
		 UFUNCTION(BlueprintCallable)
			 FString sendFStringBuilding(int i);
		 UFUNCTION(BlueprintCallable)
			 void createArrayOfBuildings();
		 UFUNCTION(BlueprintCallable)
			 ACreator* createActor();
		 UFUNCTION(BlueprintCallable)
			 void whatObject(FString name);
		 UFUNCTION(BlueprintCallable)
			 FString sendObjectName();
		 UFUNCTION(BlueprintCallable)
			 void goBack();
		 UFUNCTION(BlueprintCallable)
			 int upgradeBuilding(FString nameOfBuildingToUpgrade);
		 UFUNCTION(BlueprintCallable)
			 FString characterToBuilding1(FString nameOfCharacter,FString nameOfBuilding);
		// UFUNCTION(BlueprintCallable)
			// FString characterToBuilding2(FString nameOfCharacter, FString nameOfBuilding);
		 UFUNCTION(BlueprintCallable)
			 void createSuppliesObject();
		 UFUNCTION(BlueprintCallable)
			 void updateSupplies();
		 UFUNCTION(BlueprintCallable)
			 int showWood();
		 UFUNCTION(BlueprintCallable)
			 int showWater();
		 UFUNCTION(BlueprintCallable)
			 int showFood();
		 UFUNCTION(BlueprintCallable)
			 void nightTime();
		 UFUNCTION(BlueprintCallable)
			 FString sendFirstCharacter(FString nameOfBuilding);
	//	 UFUNCTION(BlueprintCallable)
		//	 FString sendSecondCharacter(FString nameOfBuilding);
		 UFUNCTION(BlueprintCallable)
			 int sendUpgradeLevel(FString nameOfBuilding);
		 UFUNCTION(BlueprintCallable)
			 int gameStatus();
		 UFUNCTION(BlueprintCallable)
			 int getCooking(FString nameOfCharacter);
		 UFUNCTION(BlueprintCallable)
			 int getFighting(FString nameOfCharacter);
		 UFUNCTION(BlueprintCallable)
			 int getCollecting(FString nameOfCharacter);
		 UFUNCTION(BlueprintCallable)
			 int getCollectingWater(FString nameOfCharacter);
		 UFUNCTION(BlueprintCallable)
			 bool getWorking(FString nameOfCharacter);
		 UFUNCTION(BlueprintCallable)
			 int getLightValue();
		 UFUNCTION(BlueprintCallable)
			 void setLightValue(int value);
		 UFUNCTION(BlueprintCallable)
			 void loadActor(ACreator* savedActor);
		 UFUNCTION(BlueprintCallable)
			 TArray<int> getArrayOfLevelBuildings();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfLevelBuildings(TArray<int> listOfLevel);
		 UFUNCTION(BlueprintCallable)
			 TArray<int> getArrayOfOthers();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfOthers(TArray<int> listOfOthers);

		 UFUNCTION(BlueprintCallable)
			 TArray<int> getArrayOfCollecting();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfCollecting(TArray<int> listOfCollecting);

		 UFUNCTION(BlueprintCallable)
		 TArray<int> getArrayOfWaterCollecting();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfWaterCollecting(TArray<int> listOfWaterCollecting);

		 UFUNCTION(BlueprintCallable)
		 TArray<int> getArrayOfCooking();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfCooking(TArray<int> listOfCooking);

		 UFUNCTION(BlueprintCallable)
		 TArray<int> getArrayOfFighting();
		 UFUNCTION(BlueprintCallable)
			 void setArrayOfFighting(TArray<int> listOfFighting);
		
		 UFUNCTION(BlueprintCallable)
			 int startConnection();
		 UFUNCTION(BlueprintCallable)
			 FString getName();
};

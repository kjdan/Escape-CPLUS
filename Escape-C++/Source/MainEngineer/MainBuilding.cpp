// Fill out your copyright notice in the Description page of Project Settings.

#include "MainBuilding.h"
#include "Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Creator.h"

// Sets default values
AMainBuilding::AMainBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	RootComponent = Mesh;
	Mesh->OnClicked.AddDynamic(this, &AMainBuilding::ClickOnBuilding);

}

// Called when the game starts or when spawned
void AMainBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainBuilding::ClickOnBuilding(UPrimitiveComponent * pComponent, FKey inKey)
{
	//UGameplayStatics::OpenLevel(this, "WidgetLevel");

}

FString AMainBuilding::buildingType()
{
	FString type=Mesh->GetName();
	return type;
}


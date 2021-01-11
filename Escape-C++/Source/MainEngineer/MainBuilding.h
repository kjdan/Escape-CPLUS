// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainBuilding.generated.h"

UCLASS()
class MAINENGINEER_API AMainBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UFUNCTION()
		void ClickOnBuilding(UPrimitiveComponent* pComponent, FKey inKey);

	UFUNCTION(BlueprintCallable)
		FString buildingType();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision", "Mobile"))
class BATTLETANK_API UTankBarrelMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
	
};

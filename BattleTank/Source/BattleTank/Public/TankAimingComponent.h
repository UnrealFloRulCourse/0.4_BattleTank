// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrelMeshComponent; // Forward declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrrelMeshComponentReference(UTankBarrelMeshComponent* BarrelMeshComponentToSet);

	// TODO get the turret reference

private:
	UTankBarrelMeshComponent* BarrelMeshComponent = nullptr;
	
private:
	void MoveBarrelTowards(FVector AimDirection);
};

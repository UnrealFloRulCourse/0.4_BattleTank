// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming states
UENUM()
enum class EFiringState : uint8
{
	EReloading,
	EAiming,
	ELocked
};

class UTankBarrelMeshComponent; // Forward declaration
class UTankTurretMeshComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrrelMeshComponentReference(UTankBarrelMeshComponent* BarrelMeshComponentToSet);
	void SetTurretMeshComponentReference(UTankTurretMeshComponent* TurretMeshComponentToSet);

	

private:
	UTankBarrelMeshComponent* BarrelMeshComponent = nullptr;
	UTankTurretMeshComponent* TurretMeshComponent = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::EAiming;
	
private:
	void MoveBarrelTowards(FVector AimDirection);
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrelMeshComponent.h"
#include "TankTurretMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() { PrimaryComponentTick.bCanEverTick = false; }


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!BarrelMeshComponent) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = BarrelMeshComponent->GetSocketLocation(FName("Launcher"));
	// Calculate the outLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::SetBarrrelMeshComponentReference(UTankBarrelMeshComponent * BarrelMeshComponentToSet)
{
	if (!BarrelMeshComponentToSet) { return; }
	BarrelMeshComponent = BarrelMeshComponentToSet;
}

void UTankAimingComponent::SetTurretMeshComponentReference(UTankTurretMeshComponent * TurretMeshComponentToSet)
{
	if (!TurretMeshComponentToSet) { return; }
	TurretMeshComponent = TurretMeshComponentToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Calculate the difference between the rotation we aiming and the actual rotation 
	// of the barrelMeshComponent
	auto BarrelRotator = BarrelMeshComponent->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	BarrelMeshComponent->Elevate(DeltaRotator.Pitch);
	TurretMeshComponent->Rotate(DeltaRotator.Yaw);
}

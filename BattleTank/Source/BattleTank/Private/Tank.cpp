// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Components/InputComponent.h"
#include "TankBarrelMeshComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector HitLocation) 
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(LocalBarrelRef)) { return; }
	bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (bIsReloaded) 
	{ 
	// Spawn a projectile at the socket location on the barrel
		auto ProjectileToLaunch = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			LocalBarrelRef->GetSocketLocation(FName("Launcher")),
			LocalBarrelRef->GetSocketRotation(FName("Launcher")));

		if (ProjectileToLaunch)
		{
			ProjectileToLaunch->LaunchProjectile(LaunchSpeed);
			LastFireTime = GetWorld()->GetTimeSeconds();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to spawn projectile"))
		}
		
	}
	
}


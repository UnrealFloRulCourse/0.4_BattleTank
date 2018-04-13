// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Components/InputComponent.h"
#include "TankBarrelMeshComponent.h"
#include "Projectile.h"

void ATank::SetBarrrelMeshComponentReference(UTankBarrelMeshComponent * BarrelMeshComponentToSet)
{
	TankAimingComponent->SetBarrrelMeshComponentReference(BarrelMeshComponentToSet);
	LocalBarrelRef = BarrelMeshComponentToSet;
}

void ATank::SetTurretMeshComponentReference(UTankTurretMeshComponent * TurretMeshComponentToSet)
{
	TankAimingComponent->SetTurretMeshComponentReference(TurretMeshComponentToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// No need to protect pointer as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) 
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!LocalBarrelRef) { return; }

	// Spawn a projectile at the socket location on the barrel
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		LocalBarrelRef->GetSocketLocation(FName("Launcher")),
		LocalBarrelRef->GetSocketRotation(FName("Launcher")));
}


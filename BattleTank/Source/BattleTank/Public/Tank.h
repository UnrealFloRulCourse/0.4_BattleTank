// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declaration
class UTankBarrelMeshComponent;
class UTankTurretMeshComponent;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetBarrrelMeshComponentReference(UTankBarrelMeshComponent* BarrelMeshComponentToSet);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetTurretMeshComponentReference(UTankTurretMeshComponent* TurretMeshComponentToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	UTankAimingComponent * TankAimingComponent;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent * TankMovementComponent;


private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;

	// Local barrel reference to spawn preojectile
	UTankBarrelMeshComponent* LocalBarrelRef = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 2.f;
	
	double LastFireTime = 0;
	
};

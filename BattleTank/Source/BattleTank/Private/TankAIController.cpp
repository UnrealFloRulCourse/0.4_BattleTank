// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
		auto ControlledTank = GetControlledTank();
		auto PlayerTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Possessing : %s"), *ControlledTank->GetName())
	}

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Got : %s"), *PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player controller uninstanciated in the current world"))

	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();

	return (PlayerController) ? Cast<ATank>(PlayerController) : nullptr;
}

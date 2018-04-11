// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelMeshComponent.h"
#include "Engine/World.h"

void UTankBarrelMeshComponent::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	
	// Give a max elevation speed, and the frame time
	auto Time = GetWorld()->GetRealTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate() called at : %f"), Time)
}



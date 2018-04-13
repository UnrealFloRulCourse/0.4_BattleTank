// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelMeshComponent.h"
#include "Engine/World.h"

void UTankBarrelMeshComponent::Elevate(float RelativeSpeed)
{
	// Clamp the relative speed so we dont exceed the Max Degree per second 
	// elevation rate
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, +1.f);
	// Move the barrel the right amount this frame
	// Give a max elevation speed, and the frame time
	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}



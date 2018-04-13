// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurretMeshComponent.h"
#include "Engine/World.h"

void UTankTurretMeshComponent::Rotate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	auto RotationChange = ClampedRelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRawRotation = RelativeRotation.Yaw  + RotationChange;

	SetRelativeRotation(FRotator(0, NewRawRotation, 0));

}



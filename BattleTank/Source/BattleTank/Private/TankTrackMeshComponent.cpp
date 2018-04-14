// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrackMeshComponent.h"

void UTankTrackMeshComponent::SetThrottle(float ThrottleValueInput)
{
	// TODO clamp the actual throttle value so the player cannot over drive

	auto ForceApplied = GetForwardVector() * ThrottleValueInput * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



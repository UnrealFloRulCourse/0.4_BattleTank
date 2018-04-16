// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankTrackMeshComponent.h"

void UTankMovementComponent::Initialise(UTankTrackMeshComponent* LeftTrackToSet, UTankTrackMeshComponent* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("%f : %s is moving along : %s"), GetWorld()->GetTimeSeconds(), *GetOwner()->GetName(), *MoveVelocity.GetSafeNormal().ToString())
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO prevent double speed due to multiple input
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	// TODO prevent double speed due to multiple input
}

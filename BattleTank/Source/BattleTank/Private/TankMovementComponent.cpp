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
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	// The required amount of "forward" throttle needed to go towards the player
	float ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
	float RightwardThrow = FVector::CrossProduct(AIForwardIntention, TankForward).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightwardThrow);
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

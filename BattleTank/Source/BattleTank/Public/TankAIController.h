// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UNavMovementComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* ControlledTank = nullptr;
	ATank* PlayerTank = nullptr;


	// How close can the AI tank get
	float AcceptanceRadius = 0;

public:
	ATank * GetControlledTank() const;
	ATank * GetPlayerTank() const;

};

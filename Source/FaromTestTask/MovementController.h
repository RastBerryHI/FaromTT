// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MovementController.generated.h"

/**
 * 
 */
UCLASS()
class FAROMTESTTASK_API AMovementController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY()
	class APlayerPawn* PossessedPawn;

	ENetRole CurrentRole;
public:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;

	void MoveHorizontal(float Value);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_PlayerAuthPossess(APlayerPawn* InPawn);
	bool Server_PlayerAuthPossess_Validate(APlayerPawn* InPawn);
	void Server_PlayerAuthPossess_Implementation(APlayerPawn* InPawn);
};

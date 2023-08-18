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

	UPROPERTY(Replicated)
	class APlayerPawn* PossessedPawn;

	ENetRole CurrentRole;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

public:
	~AMovementController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;

	void MoveHorizontal(float Value);

	UFUNCTION(Server, Reliable)
	void Server_PropogateMovement(float Value);
	void Server_PropogateMovement_Implementation(float Value);

};

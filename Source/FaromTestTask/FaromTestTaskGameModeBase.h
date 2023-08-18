// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerPawn.h"
#include "ABallZone.h"
#include "FaromTestTaskGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FAROMTESTTASK_API AFaromTestTaskGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Initialization")
	TSubclassOf<APlayerPawn> ActorClass;

	UPROPERTY(EditAnywhere, Category = "Initialization")
	TSubclassOf<AABallZone> ZoneClass;

	UPROPERTY(EditAnywhere, Category = "Initialization")
	FVector BallStart;

	int32 ConnectedPlayers;

	TArray<AActor*> ZoneActors;
	TArray<AActor*> OutActors;

	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	void OnBallEnter(AABallZone* BallZone);
};

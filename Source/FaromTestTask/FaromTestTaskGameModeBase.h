// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerPawn.h"
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

	int32 ConnectedPlayers;

	virtual void PostLogin(APlayerController* NewPlayer) override;
};

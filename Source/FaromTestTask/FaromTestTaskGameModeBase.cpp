// Copyright Epic Games, Inc. All Rights Reserved.


#include "FaromTestTaskGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ABallZone.h"
#include "BallSpawner.h"
#include "Ball.h"

void AFaromTestTaskGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	OutActors = {};
	ZoneActors = {};

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, OutActors);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ZoneClass, ZoneActors);

	NewPlayer->Possess(Cast<APawn>(OutActors[ConnectedPlayers++]));
}

void AFaromTestTaskGameModeBase::OnBallEnter(AABallZone* BallZone)
{
	UE_LOG(LogTemp, Warning, TEXT("Ball Enter"));
}

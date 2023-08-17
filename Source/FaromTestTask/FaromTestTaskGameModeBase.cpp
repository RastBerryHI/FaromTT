// Copyright Epic Games, Inc. All Rights Reserved.


#include "FaromTestTaskGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AFaromTestTaskGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	TArray<AActor*> OutActors = {};

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, OutActors);

	NewPlayer->Possess(Cast<APawn>(OutActors[ConnectedPlayers++]));
}

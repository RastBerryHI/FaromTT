
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallSpawner.generated.h"

UCLASS()
class FAROMTESTTASK_API ABallSpawner : public AActor
{
	GENERATED_BODY()

public:	
	ABallSpawner();

public:
	void SpawnBall();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABallZone.generated.h"

UCLASS()
class FAROMTESTTASK_API AABallZone : public AActor
{
	GENERATED_BODY()

	class UBoxComponent* BoxComponent;

    UFUNCTION()
    void HandleOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );

public:	
	AABallZone();

protected:
	virtual void BeginPlay() override;
};

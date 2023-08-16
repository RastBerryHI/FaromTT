// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComp;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToLocation(DeltaTime);
}

void APlayerPawn::MoveToLocation(float Delta)
{
	if (!MovementDirection.IsZero()) 
	{
		const FVector NewLocation = GetActorLocation() + (MovementDirection * MovementSpeed * Delta);
		SetActorLocation(NewLocation);
		UE_LOG(LogTemp, Warning, TEXT("%s %f %f %f"), *GetName(), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
	}
}


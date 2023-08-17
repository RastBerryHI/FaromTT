// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Net/UnrealNetwork.h>

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

void APlayerPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(APlayerPawn, IsPossessed, COND_OwnerOnly);
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


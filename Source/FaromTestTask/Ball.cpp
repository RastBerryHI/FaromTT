

#include "Ball.h"
#include "Components/SphereComponent.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = SphereComponent;
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	Server_PushBall();
}

bool ABall::Server_PushBall_Validate()
{
	return true;
}

void ABall::Server_PushBall_Implementation()
{
	if (SphereComponent) 
	{
		SphereComponent->AddImpulse(FVector(InitialForce, FMath::RandRange(MinYForce, MaxYForce), 0));
	}
}


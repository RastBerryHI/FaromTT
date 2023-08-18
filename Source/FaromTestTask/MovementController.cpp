
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "PlayerPawn.h"
#include "MovementController.h"

AMovementController::~AMovementController()
{
}

void AMovementController::BeginPlay()
{
	Super::BeginPlay();
}

void AMovementController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("HorizontalMove", this, &AMovementController::MoveHorizontal);
}

void AMovementController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const 
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMovementController, PossessedPawn);
}

void AMovementController::OnPossess(APawn* InPawn)
{
	PossessedPawn = Cast<APlayerPawn>(InPawn);
}

void AMovementController::MoveHorizontal(float Value)
{
	if (!HasAuthority())
	{
		Server_PropogateMovement(Value);
	}
	else 
	{
		if (PossessedPawn)
		{
			FVector Direction(0, Value, 0);
			PossessedPawn->SetMovementDirection(Direction);
		}
	}
}

void AMovementController::Server_PropogateMovement_Implementation(float Value)
{
	if (PossessedPawn)
	{
		FVector Direction(0, Value, 0);
		PossessedPawn->SetMovementDirection(Direction);
	}
}

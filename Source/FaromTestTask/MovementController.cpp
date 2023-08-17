
#include "Kismet/GameplayStatics.h"
#include "MovementController.h"
#include "PlayerPawn.h"

void AMovementController::BeginPlay()
{
	Super::BeginPlay();
}

void AMovementController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("HorizontalMove", this, &AMovementController::MoveHorizontal);
}

void AMovementController::OnPossess(APawn* InPawn)
{
	PossessedPawn = Cast<APlayerPawn>(InPawn);
}

void AMovementController::MoveHorizontal(float Value)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Client move"));
	}
	if (PossessedPawn)
	{
		FVector Direction (0, Value, 0);
		PossessedPawn->SetMovementDirection(Direction);
	}
}

bool AMovementController::Server_PlayerAuthPossess_Validate(APlayerPawn* InPawn)
{
	return true;
}

void AMovementController::Server_PlayerAuthPossess_Implementation(APlayerPawn* InPawn)
{
	Possess(InPawn);

	InPawn->IsPossessed = true;
}

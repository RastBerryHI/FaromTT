
#include "Kismet/GameplayStatics.h"
#include "MovementController.h"
#include "PlayerPawn.h"

void AMovementController::BeginPlay()
{
	OutActors = {};
	if (IsValid(ActorClass)) 
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, OutActors);
		for (AActor* actor : OutActors)
		{
			APawn* InPawn = Cast<APawn>(actor);
			if (!InPawn->GetController()) 
			{
				Possess(InPawn);
				return;
			}
		}
	}
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
	if (PossessedPawn)
	{
		FVector Direction (0, Value, 0);
		PossessedPawn->SetMovementDirection(Direction);
	}
}

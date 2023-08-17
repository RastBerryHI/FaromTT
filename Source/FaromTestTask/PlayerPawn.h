
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class FAROMTESTTASK_API APlayerPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Movement Properties")
	FVector MovementDirection;

	UPROPERTY(EditAnywhere, Category = "Movement Properties")
	float MovementSpeed = 500.f;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	void MoveToLocation(float Delta);

public:
	APlayerPawn();

	UPROPERTY(Replicated)
	bool IsPossessed;

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE void SetMovementDirection(const FVector& Direction) 
	{
		MovementDirection = Direction;
	}
};

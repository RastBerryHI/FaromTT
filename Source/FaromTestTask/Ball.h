
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.generated.h"

UCLASS()
class FAROMTESTTASK_API ABall : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* SphereComponent;

	UPROPERTY(EditAnywhere, category = "Pong parameters", meta = (AllowPrivateAccess = true))
	float InitialForce = 200000.f;

	UPROPERTY(EditAnywhere, category = "Pong parameters", meta = (AllowPrivateAccess = true))
	int32 MinYForce = -50000;

	UPROPERTY(EditAnywhere, category = "Pong parameters", meta = (AllowPrivateAccess = true))
	int32 MaxYForce = 50000;

public:
	ABall();

protected:
	virtual void BeginPlay() override;

public:	

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_PushBall();
	bool Server_PushBall_Validate();
	void Server_PushBall_Implementation();
};


#include "Components/BoxComponent.h"
#include "ABallZone.h"
#include "Ball.h"
#include "FaromTestTaskGameModeBase.h"

AABallZone::AABallZone()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComponent;

	BoxComponent->SetCollisionProfileName("OverlapAll"); 
	BoxComponent->SetGenerateOverlapEvents(true); 
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly); 

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AABallZone::HandleOverlap);
}

void AABallZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABallZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	Cast<AFaromTestTaskGameModeBase>(GetWorld()->GetAuthGameMode())->OnBallEnter(this);
}




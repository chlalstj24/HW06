#include "MovingStool.h"

AMovingStool::AMovingStool()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    MoveSpeed = 200.0f;
    MaxRange = 500.0f;
}

void AMovingStool::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    GetWorld()->GetTimerManager().SetTimer(
        DestroyTimerHandle,
        this,
        &AMovingStool::DestroyStool,
        7.5f,
        false
    );
}

void AMovingStool::DestroyStool()
{
    Destroy();
}

void AMovingStool::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector CurrentLocation = GetActorLocation();
    float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
    if (DistanceMoved >= MaxRange)
    {
        MoveSpeed = -MoveSpeed;
    }
    else if (DistanceMoved <= 5.0f && MoveSpeed < 0)
    {
        MoveSpeed = -MoveSpeed;
    }
    CurrentLocation.X += MoveSpeed * DeltaTime;
    SetActorLocation(CurrentLocation);
}
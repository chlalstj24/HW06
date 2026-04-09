#include "Spawner.h"
#include "Engine/World.h"

ASpawner::ASpawner()
{
    USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    SetRootComponent(Root);

    SpawnCount = 3;
    SpawnRadius = 400.0f;
}

void ASpawner::BeginPlay()
{
    Super::BeginPlay();
    SpawnActors();
}

void ASpawner::SpawnActors()
{
    if (!ActorToSpawn) return;

    UWorld* World = GetWorld();
    if (World)
    {
        for (int32 i = 0; i < SpawnCount; i++)
        {
            float RandX = FMath::RandRange(-SpawnRadius, SpawnRadius);
            float RandY = FMath::RandRange(-SpawnRadius, SpawnRadius);

            FVector SpawnLocation = GetActorLocation() + FVector(RandX, RandY, 0.0f);
            FRotator SpawnRotation = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

            World->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation);
        }
    }
}
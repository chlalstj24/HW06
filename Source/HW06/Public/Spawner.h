#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class HW06_API ASpawner : public AActor
{
    GENERATED_BODY()

public:
    ASpawner();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Spawner|Settings")
    TSubclassOf<AActor> ActorToSpawn;

    UPROPERTY(EditAnywhere, Category = "Spawner|Settings")
    int32 SpawnCount;

    UPROPERTY(EditAnywhere, Category = "Spawner|Settings")
    float SpawnRadius;

    void SpawnActors();
};
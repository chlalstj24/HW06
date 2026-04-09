#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingStool.generated.h"

UCLASS()
class HW06_API AMovingStool : public AActor
{
    GENERATED_BODY()

public:
    AMovingStool();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoolSettings")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoolSettings")
    float MaxRange;

    FTimerHandle DestroyTimerHandle;
    void DestroyStool();

    FVector StartLocation;

public:
    virtual void Tick(float DeltaTime) override;
};
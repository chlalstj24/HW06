#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationPotion.generated.h"

UCLASS()
class HW06_API ARotationPotion : public AActor
{
	GENERATED_BODY()

public:
	ARotationPotion();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotationPotion|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationPotion|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RotationPotion|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
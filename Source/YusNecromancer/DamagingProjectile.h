// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "DamagingProjectile.generated.h"

UCLASS()
class YUSNECROMANCER_API ADamagingProjectile : public AActor {
  GENERATED_BODY()

public: // STATE
  float fTimer = 5.f;
  AActor *Owner = nullptr;

  // Projectile movement component.
  UPROPERTY(VisibleAnywhere, Category = Movement)
  UProjectileMovementComponent *ProjectileMovementComponent;

private: // HANDLERS
  UFUNCTION()
  void TriggerEnter(class UPrimitiveComponent *HitComp,
                    class AActor *OtherActor,
                    class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,
                    bool bFromSweep, const FHitResult &SweepResult);

public:
  // Sets default values for this actor's properties
  ADamagingProjectile();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Sphere collision component.
  UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
  USphereComponent *CollisionComponent;
};

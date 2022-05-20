// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "StatsComponent.h"

#include "RoflikMovementComponent.generated.h"

#define DEFAULT_SPEED 100.f
#define ACCELERATION_DUE_TO_GRAVITY 800.f

UCLASS()
class YUSNECROMANCER_API URoflikMovementComponent
    : public UPawnMovementComponent {
  GENERATED_BODY()

private:
  /**
   * @brief ParentMeshComponent The mesh component of Roflik
   * If set, the move component will rotate the mesh component towards the
   * movement direction.
   */
  USceneComponent *ParentMeshComponent;

  UStatsComponent *ParentStatsComponent;

  UPROPERTY(VisibleAnywhere)
  /**
   * @brief FGravitySpeed Integral of current acceleration due to gravity
   */
  float FGravitySpeed;

  // ARoflik has an access to the fields of the struct
  friend class ARoflik;

public:
  URoflikMovementComponent();

  virtual void TickComponent(float, enum ELevelTick,
                             FActorComponentTickFunction *) override;
};

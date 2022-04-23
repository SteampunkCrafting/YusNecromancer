// Fill out your copyright notice in the Description page of Project Settings.

#include "RoflikMovementComponent.h"

URoflikMovementComponent::URoflikMovementComponent() {
  this->PrimaryComponentTick.bCanEverTick = true;
  this->FGravitySpeed = 0.f;
}

void URoflikMovementComponent::TickComponent(
    float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {

  /* ---- NULLPTR CHECK ---- */
  if (!(this->PawnOwner && this->UpdatedComponent && this->ParentMeshComponent))
    return;

  /* ---- RESOURCE SAVING ---- */
  if (this->ShouldSkipUpdate(DeltaTime))
    return;

  /* ---- CONSUMING MOVEMENT VECTOR ---- */
  const FVector ControlMovementVector =
      this->ConsumeInputVector().GetClampedToMaxSize(1.f) * DeltaTime *
      DEFAULT_SPEED;
  const FVector DesiredMovementVector =
      ControlMovementVector +
      FVector(0.f, 0.f, -1.f) * this->FGravitySpeed * DeltaTime;

  FHitResult Hit;
  this->SafeMoveUpdatedComponent(DesiredMovementVector,
                                 this->UpdatedComponent->GetComponentRotation(),
                                 true, Hit);
  /* -- HANDLING FREE FALL -- */
  if (FMath::IsNearlyZero(Hit.Normal.Z))
    // If having a free fall
    this->FGravitySpeed += DeltaTime * ACCELERATION_DUE_TO_GRAVITY;
  else
    // If standing on a solid ground
    this->FGravitySpeed = 0.f;

  /* -- HANDLING WALL SLIDING -- */
  if (Hit.IsValidBlockingHit())
    this->SlideAlongSurface(DesiredMovementVector, 1.f - Hit.Time, Hit.Normal,
                            Hit);

  /* ---- ROTATING MESH ---- */
  if (!ControlMovementVector.IsNearlyZero())
    this->ParentMeshComponent->SetRelativeRotation(
        this->UpdatedComponent->GetRelativeRotation()
            .GetInverse()
            .RotateVector(ControlMovementVector)
            .Rotation());
}

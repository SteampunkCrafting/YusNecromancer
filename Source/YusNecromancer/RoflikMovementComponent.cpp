// Fill out your copyright notice in the Description page of Project Settings.

#include "RoflikMovementComponent.h"

void URoflikMovementComponent::TickComponent(
    float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {

  /* ---- CHECKING VALIDITY OF STUFF ---- */
  if (!this->PawnOwner || !this->UpdatedComponent ||
      this->ShouldSkipUpdate(DeltaTime))
    return;

  /* ---- GETTING AND CLEARING MOVEMENT VECTOR ---- */
  FVector DesiredMovementThisFrame =
      this->ConsumeInputVector().GetClampedToMaxSize2D(1.f) * DeltaTime *
      DEFAULT_SPEED;

  if (DesiredMovementThisFrame.IsNearlyZero())
    return;

  FHitResult Hit;
  this->SafeMoveUpdatedComponent(DesiredMovementThisFrame,
                                 this->UpdatedComponent->GetComponentRotation(),
                                 true, Hit);

  if (Hit.IsValidBlockingHit())
    this->SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time,
                            Hit.Normal, Hit);

  /* ---- ROTATING MESH ---- */
  if (this->ParentMeshComponent)
    this->ParentMeshComponent->SetRelativeRotation(
        this->UpdatedComponent->GetRelativeRotation()
            .GetInverse()
            .RotateVector(DesiredMovementThisFrame)
            .Rotation());
}

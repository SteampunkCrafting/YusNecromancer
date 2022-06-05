// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootDamagingProjectile.h"
#include "../DamagingProjectile.h"

void ShootDamagingProjectile::OnTrigger() {
  auto Projectile =
      this->GetOwner()->GetWorld()->SpawnActor<ADamagingProjectile>(
          ADamagingProjectile::StaticClass(),
          this->GetOwner()->GetActorLocation(),
          this->GetOwner()->GetActorRotation(), FActorSpawnParameters());
  Projectile->Owner = this->GetOwner();
  Projectile->ProjectileMovementComponent->Velocity =
      this->GetOwner()->GetMeshComponent()->GetRelativeRotation().RotateVector(
          Projectile->ProjectileMovementComponent->Velocity);
  this->SetCooldown(5.f);
}

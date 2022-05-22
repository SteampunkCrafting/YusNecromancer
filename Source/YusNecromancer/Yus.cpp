// Fill out your copyright notice in the Description page of Project Settings.

#include "Yus.h"
#include "DamagingProjectile.h"

void AYus::ShootProjectile() {
  this->GetWorld()->SpawnActor<ADamagingProjectile>(
      ADamagingProjectile::StaticClass(), this->GetActorLocation(),
      this->GetActorRotation(), FActorSpawnParameters());
}

AYus::AYus() : Super() { this->AutoPossessPlayer = EAutoReceiveInput::Player0; }

void AYus::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  this->Super::SetupPlayerInputComponent(PlayerInputComponent);
  this->InputComponent->BindAction(ACTION_MAPPING_BASIC, IE_Pressed, this,
                                   &AYus::ShootProjectile);
}

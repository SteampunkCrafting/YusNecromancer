// Fill out your copyright notice in the Description page of Project Settings.

#include "Yus.h"
#include "DamagingProjectile.h"
#include "Skills/ShootDamagingProjectile.h"

AYus::AYus() : Super() {
  this->AutoPossessPlayer = EAutoReceiveInput::Player0;
  this->SetSpecialAction(TUniquePtr<Skill>(new ShootDamagingProjectile()));
}

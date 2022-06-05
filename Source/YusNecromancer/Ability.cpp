// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability.h"

float Ability::GetCooldown() const { return this->fCooldownTimer; }

bool Ability::IsReady() const { return this->GetCooldown() <= 0.f; }

void Ability::SetCooldown(float Cooldown) { this->fCooldownTimer = Cooldown; }

Ability::~Ability() {}

void Ability::Tick(float DeltaTime) {
  if (this->GetCooldown() > 0.f)
    this->fCooldownTimer -= DeltaTime;
}

void Ability::Trigger() {
  if (this->IsReady())
    this->OnTrigger();
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Skill.h"

float Skill::GetCooldown() const { return this->fCooldownTimer; }

bool Skill::IsReady() const { return this->GetCooldown() <= 0.f; }

ARoflik *Skill::GetOwner() const { return this->Owner; }

void Skill::SetCooldown(float Cooldown) { this->fCooldownTimer = Cooldown; }

void Skill::SetOwner(ARoflik *NewOwner) { this->Owner = NewOwner; }

Skill::~Skill() {}

void Skill::Tick(float DeltaTime) {
  if (this->GetCooldown() > 0.f)
    this->fCooldownTimer -= DeltaTime;
}

void Skill::Trigger() {
  if (this->IsReady())
    this->OnTrigger();
}

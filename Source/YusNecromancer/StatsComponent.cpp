// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsComponent.h"

/* ---- UTIL ---- */

/// A possible outcome of health-damage interaction
enum struct CreatureDamageOutcome {
  DAMAGE,
  HEAL,
};

/// A logic of health-damage interaction
inline CreatureDamageOutcome CheckDamageOutcome(const CreatureType Creature,
                                                const DamageType Damage) {
  if (Creature == CreatureType::LIVING && Damage == DamageType::LIGHT)
    return CreatureDamageOutcome::HEAL;
  if (Creature == CreatureType::UNDEAD && Damage == DamageType::DARK)
    return CreatureDamageOutcome::HEAL;
  return CreatureDamageOutcome::DAMAGE;
}

/* ---- FDAMAGE ---- */

FDamage FDamage::New(const DamageType &DamageType, const unsigned &Value) {
  FDamage Dmg;
  Dmg.Type = DamageType;
  Dmg.Value = Value;
  return Dmg;
}

DamageType FDamage::GetType() const { return this->Type; }

unsigned FDamage::GetValue() const { return this->Value; }

/* ---- USTATSCOMPONENT ---- */
enum CreatureType UStatsComponent::GetType() const {
  return this->CreatureType;
}

unsigned UStatsComponent::GetMaxHealth() const { return this->MaxHealth; }

unsigned UStatsComponent::GetCurrentHealth() const {
  return this->CurrentHealth;
}

void UStatsComponent::ApplyDamage(const FDamage &Damage) {
  const enum CreatureType &Type = this->CreatureType;
  const unsigned &Max = this->MaxHealth;
  unsigned &Current = this->MaxHealth;

  const enum DamageType DamageType = Damage.GetType();
  const unsigned DamageValue = Damage.GetValue();

  if (CheckDamageOutcome(Type, DamageType) == CreatureDamageOutcome::DAMAGE)
    Current = DamageValue < Current ? Current - DamageValue : 0;
  else
    Current = DamageValue + Current < Max ? Current + DamageValue : Max;
}

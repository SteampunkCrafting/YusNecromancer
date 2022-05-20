// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsComponent.h"

/* ---- UTIL ---- */

/// A possible outcome of health-damage interaction
enum struct CreatureDamageOutcome {
  DAMAGE,
  HEAL,
};

/// A logic of health-damage interaction
inline CreatureDamageOutcome CheckDamageOutcome(const ECreatureType Creature,
                                                const EDamageType Damage) {
  if (Creature == ECreatureType::LIVING && Damage == EDamageType::LIGHT)
    return CreatureDamageOutcome::HEAL;
  if (Creature == ECreatureType::UNDEAD && Damage == EDamageType::DARK)
    return CreatureDamageOutcome::HEAL;
  return CreatureDamageOutcome::DAMAGE;
}

/* ---- FDAMAGE ---- */

FDamage FDamage::New(const EDamageType &DamageType, const unsigned &Value) {
  FDamage Dmg;
  Dmg.Type = DamageType;
  Dmg.Value = Value;
  return Dmg;
}

EDamageType FDamage::GetType() const { return this->Type; }

unsigned FDamage::GetValue() const { return this->Value; }

/* ---- USTATSCOMPONENT ---- */
enum ECreatureType UStatsComponent::GetCreatureType() const {
  return this->CreatureType;
}

float UStatsComponent::GetMaxHealthFloat() const {
  return (float)this->GetMaxHealth();
}

float UStatsComponent::GetCurrentHealthFloat() const {
  return (float)this->GetCurrentHealth();
}

uint16 UStatsComponent::GetMaxHealth() const { return this->MaxHealth; }

uint16 UStatsComponent::GetCurrentHealth() const { return this->CurrentHealth; }

void UStatsComponent::TakeDamage(const FDamage &Damage) {
  const enum ECreatureType &Type = this->CreatureType;
  const unsigned &Max = this->MaxHealth;
  unsigned &Current = this->MaxHealth;

  const enum EDamageType DamageType = Damage.GetType();
  const unsigned DamageValue = Damage.GetValue();

  if (CheckDamageOutcome(Type, DamageType) == CreatureDamageOutcome::DAMAGE)
    Current = DamageValue < Current ? Current - DamageValue : 0;
  else
    Current = DamageValue + Current < Max ? Current + DamageValue : Max;
}

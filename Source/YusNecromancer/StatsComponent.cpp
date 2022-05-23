// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsComponent.h"

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
UStatsComponent::UStatsComponent() {
  this->PrimaryComponentTick.bCanEverTick = true;
}

void UStatsComponent::TickComponent(float DeltaTime, ELevelTick,
                                    FActorComponentTickFunction *) {
  for (TDoubleLinkedList<Effect *>::TIterator Itr(this->Effects.GetHead()); Itr;
       ++Itr) {
    if (!(*Itr) || (*Itr)->IsWeathered())
      this->Effects.RemoveNode(*Itr);

    (*Itr)->OnTick(this, DeltaTime);

    if ((*Itr)->IsWeathered()) {
      delete *Itr;
      this->Effects.RemoveNode(*Itr);
    }
  }
}

void UStatsComponent::ApplyEffect(Effect *E) { this->Effects.AddHead(E); }

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

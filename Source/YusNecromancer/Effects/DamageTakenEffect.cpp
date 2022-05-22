#include "DamageTakenEffect.h"

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

/* ---- DAMAGETAKENEFFECT ---- */
void DamageTakenEffect::OnTick(UStatsComponent *Owner, float) {
  if (Owner) {
    // CREATURE STATS
    const enum ECreatureType Type = Owner->GetCreatureType();
    const unsigned Max = Owner->GetMaxHealth();

    // CREATURE STATE
    unsigned &Current = Owner->CurrentHealth;

    // DAMAGE STATS
    const enum EDamageType DamageType = this->Damage.GetType();
    const unsigned DamageValue = this->Damage.GetValue();

    // GETTING DAMAGING OUTCOME
    if (CheckDamageOutcome(Type, DamageType) == CreatureDamageOutcome::DAMAGE)
      Current = DamageValue < Current ? Current - DamageValue : 0;
    else
      Current = DamageValue + Current < Max ? Current + DamageValue : Max;
  }
  this->Weather();
}

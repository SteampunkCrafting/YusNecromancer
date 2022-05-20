#include "DamageTakenEffect.h"

void DamageTakenEffect::OnTick(UStatsComponent *Owner, float) {
  Owner->TakeDamage(this->Damage);
}

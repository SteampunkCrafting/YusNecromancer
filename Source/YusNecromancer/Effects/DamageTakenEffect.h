#pragma once
#include "../Effect.h"

class YUSNECROMANCER_API DamageTakenEffect final : public Effect {
private: // FIELDS
  FDamage Damage;

protected: // OVERRIDEN METHODS
  virtual void OnTick(UStatsComponent *, float) override;
};

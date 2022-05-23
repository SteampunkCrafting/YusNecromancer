#pragma once
#include "../Effect.h"

class YUSNECROMANCER_API DamageTakenEffect final : public Effect {
public: // FIELDS
  FDamage Damage;

protected: // OVERRIDEN METHODS
  virtual void OnTick(UStatsComponent *, float) override;
};

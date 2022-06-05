// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Skill.h"
#include "CoreMinimal.h"

/// @brief An ability, which shoots a projectile towards
/// Has a cooldown of 5 seconds
class YUSNECROMANCER_API ShootDamagingProjectile final : public Skill {
  virtual void OnTrigger() override;
};

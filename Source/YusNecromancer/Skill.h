// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Roflik.h"

/// @brief An abstract ability class
class YUSNECROMANCER_API Skill {
private: // STATE
  class ARoflik *Owner = nullptr;
  float fCooldownTimer = 0.f;

protected: // ABSTRACT METHODS
  virtual void OnTrigger() = 0;

public: // ACCESSORS
  /// @brief Gets cooldown for this ability
  virtual float GetCooldown() const final;

  /// @brief Returns true whenever a cooldown is zero
  virtual bool IsReady() const final;

  /// @brief Gets the owner Roflik of this Ability
  virtual class ARoflik *GetOwner() const final;

public: // HANDLERS
  /// @brief Performs some per-tick actions
  virtual void Tick(float DeltaTime);
  /// @brief Triggers action
  virtual void Trigger() final;

public: // MUTATORS
  /// @brief Sets cooldown for this ability
  /// This method should be called by `OnTrigger` if the ability has to relaod
  /// itself after triggering.
  virtual void SetCooldown(float) final;

  /// @brief Sets the owner Roflik of this Ability
  virtual void SetOwner(class ARoflik *) final;

public: // CONSTRUCTORS
  virtual ~Skill();
};

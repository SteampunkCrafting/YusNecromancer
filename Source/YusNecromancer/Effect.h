// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatsComponent.h"

/// An effect is a dynamic object, which
class YUSNECROMANCER_API Effect {
private: // FIELDS
  bool bIsWeathered = false;

protected: // METHODS
  /// @brief Signals that this effect has been weathered, and needs to be
  /// garbage collected.
  virtual void Weather() final;

public: // CONSTRUCTOR/DESTRUCTOR
  virtual ~Effect();

public: // ABSTRACT METHODS
  /// @brief An abstract method, that is called every tick by StatsComponent
  /// until the effect is weathered.
  /// @arg Owner -- the owner of this effect.
  virtual void OnTick(class UStatsComponent *Owner, float DeltaTime) = 0;

public: // ACCESSORS
  /// @brief Checks if the effect has been weathered.
  virtual bool IsWeathered() const final;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "CoreMinimal.h"

#include "StatsComponent.generated.h"

/// The DamageType enum defines the types of the damage,
/// which can be inflicted or taken within the game.
UENUM()
enum struct DamageType {
  /// Damages everyone
  PHYSICAL,
  /// Damages living things, but heals undead
  DARK,
  /// Damages undead things, but heals living
  LIGHT,
};

/// The CreatureType enum defines the creature
UENUM()
enum struct CreatureType {
  /// Living creatures are getting healed from
  /// light damage
  LIVING,
  /// Undead creatures are getting healed from
  /// dark damage
  UNDEAD,
};

USTRUCT()
struct FDamage {
  GENERATED_BODY()

private: // FIELDS
  UPROPERTY(VisibleAnywhere) DamageType Type;
  UPROPERTY(VisibleAnywhere) unsigned Value;

public: // CONSTRUCTORS
  static FDamage New(const DamageType &DamageType, const unsigned &Value);

public: // ACCESSORS
  unsigned GetValue() const;
  DamageType GetType() const;
};

UCLASS()
class YUSNECROMANCER_API UStatsComponent final : public UActorComponent {
  GENERATED_BODY()

private: // FIELDS
  UPROPERTY(EditAnywhere) CreatureType CreatureType = CreatureType::LIVING;
  UPROPERTY(EditAnywhere) unsigned MaxHealth = 100;
  UPROPERTY(EditAnywhere) unsigned CurrentHealth = 100;

private: // SUBCOMPONENTS
  UWidgetComponent *HealthBarComponent;

public: // ACCESSORS
  enum CreatureType GetType() const;
  unsigned GetMaxHealth() const;
  unsigned GetCurrentHealth() const;

public: // MUTATORS
  void ApplyDamage(const FDamage &);
};

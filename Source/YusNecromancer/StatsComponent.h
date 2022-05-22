// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "Containers/List.h"
#include "CoreMinimal.h"
#include "Effect.h"

#include "StatsComponent.generated.h"

/// The DamageType enum defines the types of the damage,
/// which can be inflicted or taken within the game.
UENUM()
enum struct EDamageType {
  /// Damages everyone
  PHYSICAL,
  /// Damages living things, but heals undead
  DARK,
  /// Damages undead things, but heals living
  LIGHT,
};

/// The CreatureType enum defines the creature
UENUM()
enum struct ECreatureType {
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
  UPROPERTY(EditAnywhere) EDamageType Type = EDamageType::PHYSICAL;
  UPROPERTY(EditAnywhere) uint16 Value = 10;

public: // CONSTRUCTORS
  static FDamage New(const EDamageType &DamageType, const unsigned &Value);

public: // ACCESSORS
  unsigned GetValue() const;
  EDamageType GetType() const;
};

UCLASS()
class YUSNECROMANCER_API UStatsComponent final : public UActorComponent {
  GENERATED_BODY()

  friend class DamageTakenEffect;

private: // FIELDS
  UPROPERTY(EditAnywhere) ECreatureType CreatureType = ECreatureType::LIVING;
  UPROPERTY(EditAnywhere) unsigned MaxHealth = 100;
  UPROPERTY(EditAnywhere) unsigned CurrentHealth = 100;
  TDoubleLinkedList<class Effect *> Effects;

private: // SUBCOMPONENTS
  UWidgetComponent *HealthBarComponent;

public: // BLUEPRINT ACCESSORS
  UFUNCTION(BlueprintPure) enum ECreatureType GetCreatureType() const;
  UFUNCTION(BlueprintPure) float GetMaxHealthFloat() const;
  UFUNCTION(BlueprintPure) float GetCurrentHealthFloat() const;

public: // CONSTRUCTORS
  UStatsComponent();

public: // OVERRIDES
  void TickComponent(float DeltaTime, ELevelTick,
                     FActorComponentTickFunction *) override;

public: // ACCESSORS
  uint16 GetMaxHealth() const;
  uint16 GetCurrentHealth() const;

public: // MUTATORS
  void ApplyEffect(class Effect *);
};

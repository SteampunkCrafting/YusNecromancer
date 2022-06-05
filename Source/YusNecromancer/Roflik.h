#pragma once

/* ---- INCLUDES ---- */
#include "Ability.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoflikMovementComponent.h"
#include "StatsComponent.h"
#include "StatsWidget.h"

#include "Roflik.generated.h"

/* ---- CONTROL MAPPINGS---- */
#define AXIS_MAPPING_FORWARD "ROFLIK_MOVE_FORWARD"
#define AXIS_MAPPING_RIGHT "ROFLIK_MOVE_RIGHT"
#define ACTION_MAPPING_BASIC "ROFLIK_ACTION_BASIC"
#define ACTION_MAPPING_SPECIAL "ROFLIK_ACTION_SPECIAL"
#define ACTION_MAPPING_DODGE "ROFLIK_ACTION_DODGE"
#define ACTION_MAPPING_USE "ROFLIK_ACTION_USE"
#define ACTION_MAPPING_ULTIMATE "ROFLIK_ACTION_ULTIMATE"

/* ---- CLASS DECLARATION ---- */
UCLASS()
class YUSNECROMANCER_API ARoflik : public APawn {
  GENERATED_BODY()

private: // ABILITIES
  TUniquePtr<class Ability> BasicAbility;
  TUniquePtr<class Ability> SpecialAbility;
  TUniquePtr<class Ability> DodgeAbility;
  TUniquePtr<class Ability> UseAbility;
  TUniquePtr<class Ability> UltimateAbility;

protected: // GAME MECHANICS COMPONENTS
  UPROPERTY(EditAnywhere)
  UStatsComponent *StatsComponent;

protected: // GAME DESIGN COMPONENTS
  UPROPERTY(EditAnywhere) UCameraComponent *CameraComponent;
  UPROPERTY(EditAnywhere) UStaticMeshComponent *MeshComponent;
  UPROPERTY(VisibleAnywhere) UWidgetComponent *HealthBar;

protected: // CONTROL COMPONENTS
  URoflikMovementComponent *MoveComponent;

private: // CONTROL HOOKS
  void OnMoveForward(float);
  void OnMoveRight(float);
  void OnActionBasic();
  void OnActionSpecial();
  void OnActionDodge();
  void OnActionUse();
  void OnActionUltimate();

public: // API
  void ApplyEffect(Effect *);

protected: // ROFLIK SETUP
  ARoflik();
  virtual void SetupPlayerInputComponent(class UInputComponent *) override;
  virtual void BeginPlay() override;
  virtual void Tick(float) override;
  virtual void SetBasicAction(TUniquePtr<Ability>) final;
  virtual void SetSpecialAction(TUniquePtr<Ability>) final;
  virtual void SetDodgeAction(TUniquePtr<Ability>) final;
  virtual void SetUseAction(TUniquePtr<Ability>) final;
  virtual void SetUltimateAction(TUniquePtr<Ability>) final;
};

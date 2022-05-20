#pragma once

/* ---- INCLUDES ---- */
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

/* ---- CLASS DECLARATION ---- */
UCLASS()
class YUSNECROMANCER_API ARoflik : public APawn {
  GENERATED_BODY()

private: // GAME MECHANICS COMPONENTS
  UPROPERTY(EditAnywhere) UStatsComponent *StatsComponent;

private: // GAME DESIGN COMPONENTS
  UPROPERTY(EditAnywhere) UCameraComponent *CameraComponent;
  UPROPERTY(EditAnywhere) UStaticMeshComponent *MeshComponent;
  UPROPERTY(VisibleAnywhere) UWidgetComponent *HealthBar;

private: // CONTROL COMPONENTS
  UPROPERTY(VisibleAnywhere) URoflikMovementComponent *MoveComponent;

protected: // CONTROL HOOKS
  void OnMoveForward(float);
  void OnMoveRight(float);

  void OnDodge();         // TODO
  void OnBasicAction();   // TODO
  void OnSpecialAction(); // TODO

protected: // HOOKS
  ARoflik();
  virtual void SetupPlayerInputComponent(class UInputComponent *) override;
  virtual void BeginPlay() override;
};

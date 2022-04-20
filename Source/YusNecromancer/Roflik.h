#pragma once

/* ---- INCLUDES ---- */
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Roflik.generated.h"

/* ---- CONTROL MAPPINGS---- */
#define AXIS_MAPPING_FORWARD "ROFLIK_MOVE_FORWARD"
#define AXIS_MAPPING_RIGHT "ROFLIK_MOVE_RIGHT"
#define ACTION_MAPPING_BASIC "ROFLIK_ACTION_BASIC"
#define ACTION_MAPPING_SPECIAL "ROFLIK_ACTION_SPECIAL"
#define ACTION_MAPPING_DODGE "ROFLIK_ACTION_DODGE"
#define DEFAULT_SPEED 100.f

/* ---- CLASS DECLARATION ---- */
UCLASS()
class YUSNECROMANCER_API ARoflik : public APawn {
  GENERATED_BODY()

private:
  UPROPERTY(EditAnywhere)
  UCameraComponent *CameraComponent;

  UPROPERTY(EditAnywhere)
  UStaticMeshComponent *MeshComponent;

  UPROPERTY(VisibleAnywhere)
  FVector RelativeMoveDir;

  void OnMoveForward(float);
  void OnMoveRight(float);

  void OnDodge();
  void OnBasicAction();
  void OnSpecialAction();

protected:
  virtual void BeginPlay() override;

public:
  ARoflik();
  virtual void Tick(float) override;
  virtual void SetupPlayerInputComponent(class UInputComponent *) override;
};

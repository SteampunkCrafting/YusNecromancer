// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Roflik.h"
#include "Yus.generated.h"

/**
 *
 */
UCLASS()
class YUSNECROMANCER_API AYus : public ARoflik {
  GENERATED_BODY()

private:
  void ShootProjectile();

public:
  AYus();

protected:
  virtual void SetupPlayerInputComponent(class UInputComponent *) override;
};

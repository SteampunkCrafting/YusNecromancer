// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "StatsComponent.h"

#include "StatsWidget.generated.h"

/**
 *
 */
UCLASS(Abstract)
class YUSNECROMANCER_API UStatsWidget : public UUserWidget {
  GENERATED_BODY()

protected: // FIELDS
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  const UStatsComponent *Stats;

public: // MUTATORS
  void SetTrackedStats(const UStatsComponent *TrackedStats);
};

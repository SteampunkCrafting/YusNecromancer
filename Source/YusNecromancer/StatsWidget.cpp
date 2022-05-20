// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsWidget.h"

void UStatsWidget::SetTrackedStats(const UStatsComponent *TrackedStats) {
  this->Stats = TrackedStats;
}

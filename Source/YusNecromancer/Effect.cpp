// Fill out your copyright notice in the Description page of Project Settings.

#include "Effect.h"

void Effect::Weather() { this->bIsWeathered = true; }

bool Effect::IsWeathered() const { return this->bIsWeathered; }

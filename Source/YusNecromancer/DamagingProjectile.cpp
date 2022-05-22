// Fill out your copyright notice in the Description page of Project Settings.

#include "DamagingProjectile.h"

// Sets default values
ADamagingProjectile::ADamagingProjectile() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  if (!RootComponent) {
    RootComponent = CreateDefaultSubobject<USceneComponent>(
        TEXT("ProjectileSceneComponent"));
  }
  if (!CollisionComponent) {
    // Use a sphere as a simple collision representation.
    CollisionComponent =
        CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    // Set the sphere's collision radius.
    CollisionComponent->InitSphereRadius(15.0f);
    // Set the root component to be the collision component.
    RootComponent = CollisionComponent;
  }
  if (!ProjectileMovementComponent) {
    // Use this component to drive this projectile's movement.
    ProjectileMovementComponent =
        CreateDefaultSubobject<UProjectileMovementComponent>(
            TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = 10.0f;
    ProjectileMovementComponent->MaxSpeed = 10.0f;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bShouldBounce = true;
    ProjectileMovementComponent->Bounciness = 0.3f;
    ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
  }

  // MESH COMPONENT
  UStaticMeshComponent *const Mesh =
      this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

  Mesh->SetupAttachment(this->RootComponent);

  // SETTING DEFAULT MESH
  static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
      TEXT("/Game/skeleton_sub01"));
  UStaticMesh *const Asset = MeshAsset.Object;
  Mesh->SetStaticMesh(Asset);
}

// Called when the game starts or when spawned
void ADamagingProjectile::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ADamagingProjectile::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  this->fTimer -= DeltaTime;
  if (this->fTimer <= 0.f)
    this->Destroy();
}

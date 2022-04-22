#include "Roflik.h"

ARoflik::ARoflik() {
  /* ---- VARIOUS INIT PARAMETERS ---- */
  this->PrimaryActorTick.bCanEverTick = true;
  this->AutoPossessPlayer = EAutoReceiveInput::Player0;

  /* ---- BODY SETUP ---- */
  /* -- ROOT (AND HIT CAPSULE) -- */
  {
    UCapsuleComponent *const Capsule =
        this->CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root"));
    this->RootComponent = Capsule;

    Capsule->InitCapsuleSize(15.f, 50.f);
    Capsule->SetCollisionProfileName(TEXT("Pawn"));

    this->SetActorRotation(FRotator(0.f, -45.f, 0.f));
  }
  /* -- CAMERA -- */
  {
    UCameraComponent *const Camera =
        this->CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(this->RootComponent);
    Camera->SetRelativeLocation(FVector(-250.f, 0.f, 250.f));
    Camera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
    Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
    this->CameraComponent = Camera;
  }

  /* -- MESH -- */
  {
    // MESH COMPONENT
    UStaticMeshComponent *const Mesh =
        this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->MeshComponent = Mesh;

    Mesh->SetupAttachment(this->RootComponent);

    // SETTING DEFAULT MESH
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Game/skeleton_sub01"));
    UStaticMesh *const Asset = MeshAsset.Object;
    Mesh->SetStaticMesh(Asset);
  }

  /* -- MOVEMENT -- */
  {
    this->MoveComponent =
        this->CreateDefaultSubobject<URoflikMovementComponent>(
            TEXT("Movement"));
    this->MoveComponent->UpdatedComponent = this->RootComponent;
    this->MoveComponent->ParentMeshComponent = this->MeshComponent;
  }
}

void ARoflik::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  this->Super::SetupPlayerInputComponent(PlayerInputComponent);
  this->InputComponent->BindAxis(AXIS_MAPPING_FORWARD, this,
                                 &ARoflik::OnMoveForward);
  this->InputComponent->BindAxis(AXIS_MAPPING_RIGHT, this,
                                 &ARoflik::OnMoveRight);
}

void ARoflik::OnMoveForward(float Value) {
  this->MoveComponent->AddInputVector(this->GetActorForwardVector() * Value);
}

void ARoflik::OnMoveRight(float Value) {
  this->MoveComponent->AddInputVector(this->GetActorRightVector() * Value);
}

#include "Roflik.h"

ARoflik::ARoflik() {
  /* ---- VARIOUS INIT PARAMETERS ---- */
  this->PrimaryActorTick.bCanEverTick = true;
  this->AutoPossessPlayer = EAutoReceiveInput::Player0;

  /* ---- BODY SETUP ---- */
  /* -- ROOT -- */
  {
    this->RootComponent =
        this->CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
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
    Mesh->SetupAttachment(this->RootComponent);
    this->MeshComponent = Mesh;

    // SETTING DEFAULT MESH
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Game/skeleton_sub01"));
    UStaticMesh *const Asset = MeshAsset.Object;
    Mesh->SetStaticMesh(Asset);
  }
}

void ARoflik::BeginPlay() { this->Super::BeginPlay(); }

void ARoflik::Tick(float DeltaTime) {
  this->Super::Tick(DeltaTime);

  /* ---- PERFORMING DIRECTION-RELATED ACTIONS ---- */
  if (!this->RelativeMoveDir.IsZero()) {
    this->RelativeMoveDir.Normalize();
    const auto MoveDir =
        this->GetActorRotation().RotateVector(this->RelativeMoveDir);

    // MOVEMENT TOWARDS THE GIVEN DIRECTION
    this->SetActorLocation(this->GetActorLocation() +
                           MoveDir * DEFAULT_SPEED * DeltaTime);

    // MESH ROTATES TOWARDS THE GIVEN DIRECTION
    this->MeshComponent->SetRelativeRotation(this->RelativeMoveDir.Rotation());
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
  this->RelativeMoveDir.X = FMath::Clamp(Value, -1.f, 1.f);
}

void ARoflik::OnMoveRight(float Value) {
  this->RelativeMoveDir.Y = FMath::Clamp(Value, -1.f, 1.f);
}

void ARoflik::OnDodge() {}

void ARoflik::OnBasicAction() {}

void ARoflik::OnSpecialAction() {}

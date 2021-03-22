// Copyright(C) Vadim Zhemchugov.All Rights Reserved.


#include "Characters/StoryCharacterTPP.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AStoryCharacterTPP::AStoryCharacterTPP()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom->TargetArmLength = 200.0f;

	MultiplyPitch = 45.0f;
	MultiplyYaw = 45.0f;
}

void AStoryCharacterTPP::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStoryCharacterTPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStoryCharacterTPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AStoryCharacterTPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AStoryCharacterTPP::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AStoryCharacterTPP::LookUp);
	PlayerInputComponent->BindAxis("TurnRight", this, &AStoryCharacterTPP::TurnRight);
}

void AStoryCharacterTPP::MoveForward(float value)
{
	if ((Controller) && (value != 0.0f)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, value);
	}
}

void AStoryCharacterTPP::MoveRight(float value)
{
	if ((Controller) && (value != 0.0f)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, value);
	}
}

void AStoryCharacterTPP::LookUp(float value)
{
	if ((Controller) && (value != 0.0f)) {
		AddControllerPitchInput(value * MultiplyPitch * GetWorld()->GetDeltaSeconds());
	}
}

void AStoryCharacterTPP::TurnRight(float value)
{
	if ((Controller) && (value != 0.0f)) {
		AddControllerYawInput(value * MultiplyYaw * GetWorld()->GetDeltaSeconds());
	}
}


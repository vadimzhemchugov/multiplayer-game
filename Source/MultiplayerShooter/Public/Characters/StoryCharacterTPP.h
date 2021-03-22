// Copyright (C) Vadim Zhemchugov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StoryCharacterTPP.generated.h"

UCLASS()
class MULTIPLAYERSHOOTER_API AStoryCharacterTPP : public ACharacter
{
	GENERATED_BODY()

public:
	AStoryCharacterTPP();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		float MultiplyPitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		float MultiplyYaw;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void TurnRight(float value);
};

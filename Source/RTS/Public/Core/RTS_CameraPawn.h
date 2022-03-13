// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "RTS_CameraPawn.generated.h"

/**
 *	Class for the Camera Pawn. This will handle the camera for the RTS
 */

UCLASS()
class RTS_API ARTS_CameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARTS_CameraPawn();

protected:

	// Root component of our Camera Pawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* CameraRoot;

	// Camera
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* CameraComponent;

	// Arm for the Camera
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpringArmComponent* SpringArmComponent;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

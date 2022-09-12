// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RTS_HUD.generated.h"

class ARTS_PlayerController;
class ARTS_Unit;

/**
 * 
 */
UCLASS()
class RTS_API ARTS_HUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor Color;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinimalSelectionDistance;

	ARTS_HUD();

	void BeginPlay() override;

	virtual void DrawHUD() override;

	UFUNCTION(BlueprintCallable)
	void StartSelecting();

	UFUNCTION(BlueprintCallable)
	void EndSelecting();

protected:

	// The Units that are currently selected
	TArray<ARTS_Unit*> CurrentlySelectedUnits;

	UPROPERTY(BlueprintReadWrite)
	bool bIsSelecting;

	UPROPERTY(Transient)
	FVector2D TopLeftCorner;

	UPROPERTY(Transient)
	FVector2D BottomRightCorner;

	ARTS_PlayerController* MyPlayercontroller;

	FVector2D GetMousePosition();
	
};

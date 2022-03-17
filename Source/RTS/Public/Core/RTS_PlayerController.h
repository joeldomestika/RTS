// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Units/RTS_Unit.h"
#include "RTS_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RTS_API ARTS_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ARTS_PlayerController();

	// Adding a newly selected unit
	UFUNCTION(BlueprintCallable)
	void AddSelectedUnit(ARTS_Unit* Unit);

	// Unselecting an unit
	UFUNCTION(BlueprintCallable)
	void RemoveSelectedUnit(ARTS_Unit* Unit);

	UFUNCTION(BlueprintCallable)
	void MoveSelectedUnits(FVector Location);

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ARTS_Unit*> SelectedUnits;
	
};

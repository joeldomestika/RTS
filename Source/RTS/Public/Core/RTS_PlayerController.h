// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Units/RTS_Unit.h"
#include "Buildings/RTS_Building.h"
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

	// Unselect all units
	UFUNCTION(BlueprintCallable)
	void ClearSelectedUnits();

	UFUNCTION(BlueprintCallable)
	void MoveSelectedUnits(FVector Location);

	// Select a Building
	UFUNCTION(BlueprintCallable)
	void SelecteBuilding(ARTS_Building* Building);

	// Unselect the Building
	UFUNCTION(BlueprintCallable)
	void UnselectBuilding();

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ARTS_Unit*> SelectedUnits;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ARTS_Building* SelectedBuilding;
};

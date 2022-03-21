// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RTS_PlayerController.h"

ARTS_PlayerController::ARTS_PlayerController()
{
	bEnableClickEvents = true;
}

void ARTS_PlayerController::AddSelectedUnit(ARTS_Unit* Unit)
{
	if (IsValid(Unit) && !Unit->GetIsSelected())
	{
		UnselectBuilding();

		SelectedUnits.AddUnique(Unit);
		Unit->SetIsSelected(true);
	}
}

void ARTS_PlayerController::RemoveSelectedUnit(ARTS_Unit* Unit)
{
	if (IsValid(Unit) && Unit->GetIsSelected())
	{
		SelectedUnits.Remove(Unit);
		Unit->SetIsSelected(false);
	}
}

void ARTS_PlayerController::ClearSelectedUnits()
{
	for (ARTS_Unit* Unit : SelectedUnits)
	{
		if (IsValid(Unit))
		{
			Unit->SetIsSelected(false);
		}
	}

	SelectedUnits.Empty();
}

void ARTS_PlayerController::MoveSelectedUnits(FVector Location)
{
	for (ARTS_Unit* Unit : SelectedUnits)
	{
		if (IsValid(Unit))
		{
			Unit->MoveUnit(Location);
		}
	}
}

void ARTS_PlayerController::SelectBuilding(ARTS_Building* Building)
{
	if (IsValid(Building))
	{
		ClearSelectedUnits();

		// Previously selected building
		UnselectBuilding();

		Building->SetIsSelected(true);
		SelectedBuilding = Building;
	}
}

void ARTS_PlayerController::UnselectBuilding()
{
	if (IsValid(SelectedBuilding))
	{
		SelectedBuilding->SetIsSelected(false);
	}
}

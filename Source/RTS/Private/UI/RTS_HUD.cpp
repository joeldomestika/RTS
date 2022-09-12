// Fill out your copyright notice in the Description page of Project Settings.

#include "Units/RTS_Unit.h"
#include "Core/RTS_PlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "UI/RTS_HUD.h"

ARTS_HUD::ARTS_HUD()
{
	Color = FLinearColor(0.8f, 0.5f, 0, 0.2f);
	MinimalSelectionDistance = 20.0f;
}


void ARTS_HUD::BeginPlay()
{
	Super::BeginPlay();

	MyPlayercontroller = Cast<ARTS_PlayerController>(GetOwningPlayerController());
}

void ARTS_HUD::DrawHUD()
{
	Super::DrawHUD();

	if (bIsSelecting)
	{
		BottomRightCorner= GetMousePosition();

		const float Width = BottomRightCorner.X - TopLeftCorner.X;
		const float Height = BottomRightCorner.Y - TopLeftCorner.Y;

		if (UKismetMathLibrary::Abs(Width) <= MinimalSelectionDistance || UKismetMathLibrary::Abs(Height) <= MinimalSelectionDistance)
		{
			return;
		}

		DrawRect(Color, TopLeftCorner.X, TopLeftCorner.Y, Width, Height);

		TArray<ARTS_Unit*> FoundActors;

		GetActorsInSelectionRectangle<ARTS_Unit>(TopLeftCorner, BottomRightCorner, FoundActors, false, false);

		// If a previously selected actor is not present, lets unselect it
		for (ARTS_Unit* Unit : CurrentlySelectedUnits)
		{
			if (IsValid(Unit) && IsValid(MyPlayercontroller))
			{
				if (!FoundActors.Contains(Unit))
				{
					MyPlayercontroller->RemoveSelectedUnit(Unit);
				}
			}
		}

		CurrentlySelectedUnits.Empty();

		for (ARTS_Unit* Unit : FoundActors)
		{
			if (IsValid(Unit) && IsValid(MyPlayercontroller))
			{
				if (Unit->GetTeam()== ETeam::PLAYER)
				{
					MyPlayercontroller->AddSelectedUnit(Unit);
					CurrentlySelectedUnits.Add(Unit);
				}
			}
		}
	}
}

void ARTS_HUD::StartSelecting()
{
	bIsSelecting = true;

	TopLeftCorner = GetMousePosition();

	CurrentlySelectedUnits.Empty();
}

void ARTS_HUD::EndSelecting()
{
	bIsSelecting = false;

	CurrentlySelectedUnits.Empty();
}

FVector2D ARTS_HUD::GetMousePosition()
{
	float PositionX;
	float PositionY;

	GetOwningPlayerController()->GetMousePosition(PositionX, PositionY);

	return FVector2D(PositionX, PositionY);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/RTS_Building.h"


// Sets default values
ARTS_Building::ARTS_Building()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BuildingRootComponent= CreateDefaultSubobject<USceneComponent>(TEXT("BuildingRootComponent"));
	RootComponent = BuildingRootComponent;

	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
	BuildingMesh->SetupAttachment(RootComponent);

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetVisibility(false);
	DecalComponent->SetupAttachment(RootComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ARTS_Building::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARTS_Building::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARTS_Building::EndPlay(EEndPlayReason::Type EndplayReason)
{
	RemoveBuildingWidget();
}

void ARTS_Building::SetIsSelected(bool SelectionValue)
{
	bIsSelected = SelectionValue;
	DecalComponent->SetVisibility(bIsSelected);

	if (bIsSelected)
	{
		AddBuildingWidget();
	}
	else
	{
		RemoveBuildingWidget();
	}
}

void ARTS_Building::AddBuildingWidget()
{
	if (IsValid(BuildingWidgetClass))
	{
		RemoveBuildingWidget();

		BuildingWidget = CreateWidget(GetWorld(), BuildingWidgetClass);

		if (IsValid(BuildingWidget))
		{
			BuildingWidget->AddToViewport();
			BP_SetupUI();
		}
	}
}

void ARTS_Building::RemoveBuildingWidget()
{
	if (IsValid(BuildingWidget))
	{
		BuildingWidget->RemoveFromViewport();
	}
}


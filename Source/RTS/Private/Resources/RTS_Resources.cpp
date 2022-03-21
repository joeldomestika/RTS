// Fill out your copyright notice in the Description page of Project Settings.


#include "Resources/RTS_Resources.h"

// Sets default values
ARTS_Resources::ARTS_Resources()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ResourcesRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ResourcesRootComponent"));
	RootComponent = ResourcesRootComponent;

	ResourcesMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ResourcesMesh"));
	ResourcesMesh->SetupAttachment(RootComponent);

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetVisibility(false);
	DecalComponent->SetupAttachment(RootComponent);

	MaxResources = 100;
	CurrentResources = MaxResources;
}

// Called when the game starts or when spawned
void ARTS_Resources::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentResources = MaxResources;
}

// Called every frame
void ARTS_Resources::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARTS_Resources::EndPlay(EEndPlayReason::Type EndplayReason)
{
	RemoveResourcesWidget();
}

void ARTS_Resources::SetIsSelected(bool SelectionValue)
{
	bIsSelected = SelectionValue;
	DecalComponent->SetVisibility(bIsSelected);

	if (bIsSelected)
	{
		AddResourcesWidget();
	}
	else
	{
		RemoveResourcesWidget();
	}
}

void ARTS_Resources::AddResourcesWidget()
{
	if (IsValid(ResourcesWidgetClass))
	{
		RemoveResourcesWidget();

		ResourcesWidget = CreateWidget(GetWorld(), ResourcesWidgetClass);

		if (IsValid(ResourcesWidget))
		{
			ResourcesWidget->AddToViewport();
		}
	}
}

void ARTS_Resources::RemoveResourcesWidget()
{
	if (IsValid(ResourcesWidget))
	{
		ResourcesWidget->RemoveFromViewport();
	}
}


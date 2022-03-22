// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DecalComponent.h"
#include "Blueprint/UserWidget.h"
#include "RTS_Building.generated.h"

// Base building implementation

UCLASS()
class RTS_API ARTS_Building : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARTS_Building();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// This Unit is selected ?
	bool bIsSelected;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* BuildingRootComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UDecalComponent* DecalComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* BuildingMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> BuildingWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UUserWidget* BuildingWidget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(EEndPlayReason::Type EndplayReason) override;

	// Obtain if the building is currently selected or not
	UFUNCTION(BlueprintCallable)
	bool GetIsSelected() { return bIsSelected; }

	// Set if the building is selected or not
	UFUNCTION(BlueprintCallable)
	void SetIsSelected(bool SelectionValue);

	UFUNCTION(BlueprintCallable)
	void AddBuildingWidget();

	UFUNCTION(BlueprintCallable)
	void RemoveBuildingWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void SetupUI();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DecalComponent.h"
#include "Blueprint/UserWidget.h"
#include "RTS_Resources.generated.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	WOOD UMETA(DisplayName = "Wood"),
	FOOD UMETA(DisplayName = "Food"),
	STONE UMETA(DisplayName = "Stone"),
};

// Resources on our RTS

UCLASS()
class RTS_API ARTS_Resources : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARTS_Resources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// This Unit is selected ?
	bool bIsSelected;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* ResourcesRootComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UDecalComponent* DecalComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* ResourcesMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ResourcesWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UUserWidget* ResourcesWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int MaxResources;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
	int CurrentResources;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	EResourceType ResourceType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(EEndPlayReason::Type EndplayReason) override;

	// Obtain if the Resource is currently selected or not
	UFUNCTION(BlueprintCallable)
	bool GetIsSelected() { return bIsSelected; }

	// Set if the Resource is selected or not
	UFUNCTION(BlueprintCallable)
	void SetIsSelected(bool SelectionValue);

	UFUNCTION(BlueprintCallable)
	void AddResourcesWidget();

	UFUNCTION(BlueprintCallable)
	void RemoveResourcesWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void SetupUI();

	// Consumes resources
	UFUNCTION(BlueprintCallable)
	void ConsumeResources(int ResourcesConsumed);

	// Obtain the current Resources
	UFUNCTION(BlueprintCallable)
	int GetResources() { return CurrentResources; }

};

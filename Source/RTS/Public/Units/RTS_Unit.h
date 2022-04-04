// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/DecalComponent.h"
#include "Components/HealthComponent.h"
#include "RTS_Unit.generated.h"

// Base unit implementation

UCLASS()
class RTS_API ARTS_Unit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARTS_Unit();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	int CostWood;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	int CostFood;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	int CostStone;

protected:

	// This Unit is selected ?
	bool bIsSelected;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UDecalComponent* DecalComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UHealthComponent* HealthComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Obtain if the unit is currently selected or not
	UFUNCTION(BlueprintCallable)
	bool GetIsSelected() { return bIsSelected; }

	// Set if the unit is selected or not
	UFUNCTION(BlueprintCallable)
	void SetIsSelected(bool SelectionValue);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void BP_MoveUnit(FVector Location);
};

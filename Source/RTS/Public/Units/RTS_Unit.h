// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/DecalComponent.h"
#include "Components/HealthComponent.h"
#include "GameplayTagAssetInterface.h"
#include "RTS_Unit.generated.h"

// Base unit implementation

UCLASS()
class RTS_API ARTS_Unit : public ACharacter, public IGameplayTagAssetInterface
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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Description")
	float ConstructionTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameplayTags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = GameplayTags; }

protected:

	// This Unit is selected ?
	bool bIsSelected;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDecalComponent* DecalComponent;

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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_MoveUnit(FVector Location);

	UFUNCTION()
	ETeam GetTeam();
};

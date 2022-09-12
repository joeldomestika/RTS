// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// Combat type of the object with the health component
UENUM(BlueprintType)
enum class ECombatType : uint8
{
	NONE UMETA(DisplayName = "None"), // No combat type
	ARMORED UMETA(DisplayName = "Armored"), // for units like the tank
	ANTIARMOR UMETA(DisplayName = "Anti armor"), // for units like the assault vehicle
	REGULAR UMETA(DisplayName = "Regular"), // For regular units
};

// Team, either player or opponent AI
UENUM(BlueprintType)
enum class ETeam : uint8
{
	PLAYER UMETA(DisplayName = "Player"), // Player team
	COMPUTER UMETA(DisplayName = "Computer"), // Computer AI controlled team
	NONE UMETA(DisplayName = "None"), // No team
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, bool, bIsDead);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

// Component to handle health
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
	bool bIsDeath;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECombatType CombatType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETeam Team;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float WeakCombatMultiplier;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float StrongCombatMultiplier;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FOnDeath OnDeath;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	ECombatType GetCombatType() { return CombatType; }

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() { return MaxHealth; }

	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth() { return Health; }

	UFUNCTION(BlueprintCallable)
	float IsDead() { return bIsDeath; }

	UFUNCTION(BlueprintCallable)
	float GetCombatMultiplier(ECombatType OpponentCombatType);

	UFUNCTION(BlueprintCallable)
	bool AddDamage(float Damage, ECombatType OpponentCombatType = ECombatType::NONE, ETeam OpponentTeam = ETeam::COMPUTER);

	UFUNCTION(BlueprintCallable)
	ETeam GetTeam();
};

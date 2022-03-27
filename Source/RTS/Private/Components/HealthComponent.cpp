// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100.0f;
	Health = MaxHealth;
	bIsDeath = false;

	WeakCombatMultiplier = 0.5f;
	StrongCombatMultiplier = 1.5f;

	Team = ETeam::PLAYER;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UHealthComponent::GetCombatMultiplier(ECombatType OpponentCombatType)
{
	if (CombatType == OpponentCombatType) return 1.0f;

	if (CombatType == ECombatType::ARMORED && CombatType == ECombatType::ANTIARMOR) return WeakCombatMultiplier;

	if (CombatType == ECombatType::ARMORED && CombatType == ECombatType::REGULAR) return StrongCombatMultiplier;

	if (CombatType == ECombatType::REGULAR && CombatType == ECombatType::ANTIARMOR) return StrongCombatMultiplier;

	if (CombatType == ECombatType::REGULAR && CombatType == ECombatType::ARMORED) return WeakCombatMultiplier;

	if (CombatType == ECombatType::ANTIARMOR && CombatType == ECombatType::ARMORED) return StrongCombatMultiplier;

	if (CombatType == ECombatType::ANTIARMOR && CombatType == ECombatType::REGULAR) return WeakCombatMultiplier;

	return 1.0f;
}

bool UHealthComponent::AddDamage(float Damage, ECombatType OpponentCombatType /*= ECombatType::NONE*/, ETeam OpponentTeam /*= ETeam::COMPUTER*/)
{

	if (Team == OpponentTeam)
	{
		return false;
	}

	float CombatMultiplier = GetCombatMultiplier(OpponentCombatType);

	Health = Health - CombatMultiplier * Damage;

	if (Health < 0)
	{
		Health = 0;

		bIsDeath = true;

		BP_OnDeath();
	}

	return bIsDeath;
}


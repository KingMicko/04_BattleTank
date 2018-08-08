// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include <UnrealMathUtility.h>

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP BeginPlay to run
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth: %s  StartingHealth: %s"), CurrentHealth, StartingHealth);
	return (float)CurrentHealth / (float)StartingHealth;
}

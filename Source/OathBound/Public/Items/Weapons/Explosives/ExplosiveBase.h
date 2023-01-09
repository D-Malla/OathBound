// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/WeaponBase.h"
#include "ExplosiveBase.generated.h"

/**
 * 
 */
UCLASS()
class OATHBOUND_API AExplosiveBase : public AWeaponBase
{
	GENERATED_BODY()

public:

	AExplosiveBase();

protected:

private:

	// Explosive Properties
	UPROPERTY(EditDefaultsOnly, Category = "Explosives | Base")
	uint16 ExplosiveCount;

	UPROPERTY(EditDefaultsOnly, Category = "Explosives | Base")
	uint16 ExplosiveCountMax;

	UPROPERTY(EditDefaultsOnly, Category = "Explosives | Base")
	float DamageRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Explosives | Base")
	float ThrowDistance;
	
};

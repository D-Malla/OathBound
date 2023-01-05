// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponBase.h"
#include "GunBase.generated.h"

/**
 * 
 */
UCLASS()
class OATHBOUND_API AGunBase : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	AGunBase();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Gun | Base")
	float ShootSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Gun | Base")
	uint16 BulletCount;
	UPROPERTY(EditDefaultsOnly, Category = "Gun | Base")
	uint16 BulletCountMax;
	UPROPERTY(EditDefaultsOnly, Category = "Gun | Base")
	float ReloadTime;
};

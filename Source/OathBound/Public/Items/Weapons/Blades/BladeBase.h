// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/WeaponBase.h"
#include "BladeBase.generated.h"

UCLASS()
class OATHBOUND_API ABladeBase : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	ABladeBase();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Blade | Base")
	UBoxComponent* BladeCollision;

	UPROPERTY(EditDefaultsOnly, Category = "Blade | Base")
	float AttackSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Blade | Base")
	bool bIsSharp;
	UPROPERTY(EditDefaultsOnly, Category = "Blade | Base")
	float ResharpenTime;
};

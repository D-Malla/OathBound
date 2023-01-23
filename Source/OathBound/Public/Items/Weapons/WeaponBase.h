// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/ItemBase.h"
#include "WeaponBase.generated.h"

class USphereComponent;

UENUM()
enum class EWeaponType
{
	EWT_Blade				UMETA(DisplayName = "Blade"),
	EWT_Explosive		UMETA(DisplayName = "Explosive"),
	EWT_Gun					UMETA(DisplayName = "Gun"),
	EWT_DEFAULTMAX	UMETA(DisplayName = "DefaultMax")
};

UCLASS()
class OATHBOUND_API AWeaponBase : public AItemBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Weapon Core Components
	UPROPERTY(EditDefaultsOnly, Category = "Item | Weapon | Base")
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Weapon | Base")
	TSubclassOf<UTexture2D> WeaponIcon;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Weapon | Base")
	EWeaponType WeaponType;


public:
	FORCEINLINE EWeaponType GetWeaponType() { return WeaponType; }
};

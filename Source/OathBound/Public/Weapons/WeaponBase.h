// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UBoxComponent;
class USoundCue;
class UTexture2D;

UENUM()
enum class EWeaponType
{
	EWT_Blade				UMETA(DisplayName = "Blade"),
	EWT_Bomb				UMETA(DisplayName = "Bomb"),
	EWT_Gun					UMETA(DisplayName = "Gun"),
	EWT_DEFAULTMAX	UMETA(DisplayName = "DefaultMax")
};

UCLASS()
class OATHBOUND_API AWeaponBase : public AActor
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
	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	UBoxComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	USoundCue* EquipSound;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	USoundCue* UnEquipSound;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	FString ID;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	EWeaponType WeaponType;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon | Base")
	TSubclassOf<UTexture2D> WeaponIcon;
};

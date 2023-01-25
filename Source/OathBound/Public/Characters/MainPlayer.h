// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Interfaces/PickupInterface.h"
#include "MainPlayer.generated.h"
 
class ABladeBase;
class AItemBase;
class AWeaponBase;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;

UENUM()
enum class EEquippedWeapon
{
	EEW_UNEQUIPPED				UMETA(DisplayName = "Unequipped"),
	EEW_BLADEEQUIPPED			UMETA(DisplayName = "BladeEquipped"),
	EEW_GUNEQUIPPED				UMETA(DisplayName = "GunEquipped"),
	EEW_EXPLOSIVEEQUIPPED UMETA(DisplayName = "ExplosiveEquipped"),
	EEW_DEFAULTMAX				UMETA(DisplayName = "DefaultMax")
};


UCLASS()
class OATHBOUND_API AMainPlayer : public ACharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// PickupInterface functionality
	virtual void SetOverlappingItem(AItemBase* Item) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Damage(float DamageAmount);
	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount);

private:
	/* Core Components */
	UPROPERTY(VisibleAnywhere, Category = "Main | Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Main | Components")
	UCameraComponent* CameraComponent;

	/* States */
	UPROPERTY(VisibleAnywhere, Category = "Main | States")
	EEquippedWeapon EquippedWeapon;

	/* Weapon Components */
	UPROPERTY(EditDefaultsOnly, Category = "Main | Weapons")
	USkeletalMeshComponent* PrimarySwordComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Main | Weapons")
	USkeletalMeshComponent* PrimaryPistolComponent;

	//UPROPERTY(EditDefaultsOnly, Category = "Main | Weapons")
	//USkeletalMeshComponent* SecondaryWeaponComponent; // This can be another off-hand pistol or knife. 1 quick use to save the player's ass.

	//UPROPERTY(EditDefaultsOnly, Category = "Main | Weapons")
	//USkeletalMeshComponent* BombWeaponComponent;

	/* Input */
	UPROPERTY(EditAnywhere, Category = "Main | Input")
		UInputMappingContext* MainPlayerContext;

	UPROPERTY(EditAnywhere, Category = "Main | Input")
		UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Main | Input")
		UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Main | Input")
		UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Main | Input")
	UInputAction* PickupAction;

	/*  Input Callback Functions */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Jump() override;
	void EKeyPressed();

	/* Stats */ 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Stats", meta = (AllowPrivateAccess = "true"))
		float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main | Stats", meta = (AllowPrivateAccess = "true"))
		float Health;

	/* Combat */
	
	/* Pickup */
	UPROPERTY(VisibleInstanceOnly)
	AItemBase* OverlappingItem;

	

public:
	/* Getter Functions */
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }
	FORCEINLINE float GetHealth() const { return Health; }
	FORCEINLINE EEquippedWeapon SetEquippedWeapon(EEquippedWeapon WeaponEquippedState) { EquippedWeapon = WeaponEquippedState; }
};

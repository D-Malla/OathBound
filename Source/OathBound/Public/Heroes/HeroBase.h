// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "HeroBase.generated.h"

class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;

UCLASS()
class OATHBOUND_API AHeroBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeroBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Damage(float DamageAmount);
	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount);

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Hero | Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Hero | Components")
	UCameraComponent* CameraComponent;

	// Input
	UPROPERTY(EditAnywhere, Category = "Hero | Input")
	UInputMappingContext* HeroContext;

	UPROPERTY(EditAnywhere, Category = "Hero | Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Hero | Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Hero | Input")
	UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Jump() override;

	// Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hero | Stats", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hero | Stats", meta = (AllowPrivateAccess = "true"))
	float Health;

public:
	// Getter Functions
	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }
};

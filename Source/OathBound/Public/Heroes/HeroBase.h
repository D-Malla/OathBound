// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HeroBase.generated.h"

class UCameraComponent;
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

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* HairComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* EyeBrowComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* BeardComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* BeltComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* BootsComponent;
};

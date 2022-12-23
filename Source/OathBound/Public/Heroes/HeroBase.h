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

	// Character Customization
	//UPROPERTY(VisibleAnywhere, Category = "Character | Customization")
	//bool bIsMale;
	//UPROPERTY(VisibleAnywhere, Category = "Character | Customization")
	//bool bIsFemale;

	UPROPERTY(VisibleAnywhere, Category = "Character | Customization")
	USkeletalMeshComponent* Hair;
	UPROPERTY(VisibleAnywhere, Category = "Character | Customization")
	USkeletalMeshComponent* Eyebrows;
	UPROPERTY(VisibleAnywhere, Category = "Character | Customization")
	USkeletalMeshComponent* Beard;

	//Equipment
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent*	Bracers;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Belt;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Boots;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Cape;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Chest;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Hands;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent*	Helm;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent*	Legs;
	UPROPERTY(VisibleAnywhere, Category = "Character | Equipment")
	USkeletalMeshComponent* Shoulders;
};

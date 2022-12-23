// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentBase.generated.h"

class USoundCue;

UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	EET_Armor			UMETA(DisplayName = "Armor"),
	EET_Shield		UMETA(DisplayName = "Shield"),
	EET_Weapon		UMETA(DisplayName = "Weapon"),
	EET_NONE			UMETA(DisplayName = "NONE")
};

UENUM(BlueprintType)
enum class EEquipmentRarity : uint8
{
	EER_Common		UMETA(DisplayName = "Uncommon"),
	EER_UnCommon	UMETA(DisplayName = "Common"),
	EER_Rare			UMETA(DisplayName = "Rare"),
	EER_Epic			UMETA(DisplayName = "Epic"),
	EER_Legendary	UMETA(DisplayName = "Legendary")
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OATHBOUND_API UEquipmentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipmentBase();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	FString Name;
	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	USkeletalMesh* EquipmentMesh;
	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	USoundCue* EquipSound;
	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	USoundCue* UnequipSound;
	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	float EquipmentLevelRequirement;

	UPROPERTY(VisibleAnywhere, Category = "Equipment | Equipment Type")
	EEquipmentType EquipmentType;

	UPROPERTY(VisibleAnywhere, Category = "Equipment | Stats")
	EEquipmentRarity Rarity;


};

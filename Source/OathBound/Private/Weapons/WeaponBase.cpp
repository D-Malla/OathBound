// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponBase.h"
#include "Components/BoxComponent.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundCue.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	RootComponent = WeaponCollision;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(GetRootComponent());

	EquipSound = CreateDefaultSubobject<USoundCue>(TEXT("EquipSound"));
	UnEquipSound = CreateDefaultSubobject<USoundCue>(TEXT("UnEquipSound"));

	Name = "";
	ID = "0";
	WeaponType = EWeaponType::EWT_DEFAULTMAX;
	DamageAmount = 0.f;


}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


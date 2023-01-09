// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBase.h"
#include "Components/BoxComponent.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundCue.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ItemCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ItemCollision"));
	RootComponent = ItemCollision;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(GetRootComponent());

	ItemPickupSound = CreateDefaultSubobject<USoundCue>(TEXT("PickupSound"));
	ItemDropSound = CreateDefaultSubobject<USoundCue>(TEXT("DropSound"));

	Name = "";
	ID = "0";
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


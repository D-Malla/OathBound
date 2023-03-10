// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBase.h"
#include "Characters/MainPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Interfaces/PickupInterface.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundCue.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	PickupRadius = CreateDefaultSubobject<USphereComponent>(TEXT("PickupRadius"));
	PickupRadius->SetupAttachment(GetRootComponent());

	//ItemPickupSound = CreateDefaultSubobject<USoundCue>(TEXT("PickupSound"));
	//ItemDropSound = CreateDefaultSubobject<USoundCue>(TEXT("DropSound"));

	Name = "";
	ID = "0";
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Binding item pickup radius overlap delegates
	PickupRadius->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnRadiusSphereBeginOverlap);
	PickupRadius->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnRadiusSphereEndOverlap);
}

void AItemBase::OnRadiusSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString(TEXT("Item Overlapped!!!!!!!")));
	}
	
	 //Casts to MainPlayer PickupInterface so we can access it's interface functionality. TODO: Will be casted to any Character (MainPlayer, NPC, etc.)
		IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
		if (PickupInterface)
		{
			PickupInterface->SetOverlappingItem(this); // Once Radius is overlapped, we connect to MainPlayer's PickupInterface and set the item being overlapped by MainPlayer. TODO: This will work with Enemy NPCs that will pickup weapons if they don't currently have one equipped.
		}
}

void AItemBase::OnRadiusSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->SetOverlappingItem(nullptr);
	}
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Heroes/HeroBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AHeroBase::AHeroBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Components
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	USkeletalMeshComponent* CharacterMesh = GetMesh();

	// Character Customization
	Hair = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hair"));
	Hair->SetupAttachment(CharacterMesh);

	Eyebrows = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(CharacterMesh);

	Beard = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Beard"));
	Beard->SetupAttachment(CharacterMesh);

	// Equipment
	Bracers = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Bracers"));
	Bracers->SetupAttachment(CharacterMesh);

	Belt = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Belt"));
	Belt->SetupAttachment(CharacterMesh);

	Boots = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Boots"));
	Boots->SetupAttachment(CharacterMesh);

	Cape = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Cape"));
	Cape->SetupAttachment(CharacterMesh);

	Chest = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Chest"));
	Chest->SetupAttachment(CharacterMesh);

	Hands = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hands"));
	Hands->SetupAttachment(CharacterMesh);

	Helm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Helm"));
	Helm->SetupAttachment(CharacterMesh);

	Legs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	Legs->SetupAttachment(CharacterMesh);

	Shoulders = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Shoulders"));
	Shoulders->SetupAttachment(CharacterMesh);
}

// Called when the game starts or when spawned
void AHeroBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHeroBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


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

	HairComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HairComponent"));
	HairComponent->SetupAttachment(GetMesh());

	EyeBrowComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EyebrowComponent"));
	EyeBrowComponent->SetupAttachment(GetMesh());

	BeardComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BeardComponent"));
	BeardComponent->SetupAttachment(GetMesh());

	BeltComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BeltComponent"));
	BeltComponent->SetupAttachment(GetMesh());

	BootsComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BootsComponent"));
	BootsComponent->SetupAttachment(GetMesh());
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


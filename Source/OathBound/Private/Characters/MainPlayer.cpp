// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/MainPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/PickupInterface.h"
#include "Items/Weapons/Blades/BladeBase.h"
#include "Items/Weapons/Guns/GunBase.h"
#include "Items/Weapons/Explosives/ExplosiveBase.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	USkeletalMeshComponent* MainPlayerMesh = GetMesh();

	/* Core Components */
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	/* Weapon Components */
	PrimarySwordComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PrimarySwordComponent"));
	PrimarySwordComponent->SetupAttachment(MainPlayerMesh);

	PrimaryPistolComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PrimaryPistolComponent"));
	PrimaryPistolComponent->SetupAttachment(MainPlayerMesh);

	/* States */
	EquippedWeapon = EEquippedWeapon::EEW_UNEQUIPPED;

	/* Stats */
	MaxHealth = 100.f;
	Health = MaxHealth;
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Adding Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) // Creating Subsystem (UEnhancedInputLocalPlayerSubsystem) is what will allow you add mapping contexts, bind input delegates, and more.
		{
			Subsystem->AddMappingContext(MainPlayerContext, 0);
		}
	}
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setting up Enhanced Input Component
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) // Casting PlayerInputComponent into EnhancedInputComponent
	{
		// Movement
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AMainPlayer::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainPlayer::Look);

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainPlayer::Jump);

		// Item Pickup
		EnhancedInputComponent->BindAction(PickupAction, ETriggerEvent::Triggered,this, &AMainPlayer::EKeyPressed);
	}

}

void AMainPlayer::SetOverlappingItem(AItemBase* Item)
{
	OverlappingItem = Item;
}

void AMainPlayer::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>(); // Getting the X and Y values from our Input Action

	//const FVector Forward = GetActorForwardVector();
	//const FVector Right = GetActorRightVector();

	//AddMovementInput(Forward, MovementVector.X);
	//AddMovementInput(Right, MovementVector.Y);

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void AMainPlayer::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>(); // Getting the X and Y values from our Input Action

	AddControllerPitchInput(LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);
}

void AMainPlayer::Jump()
{
	Super::Jump();
}

void AMainPlayer::EKeyPressed()
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Green,
		FString(TEXT("E KEY PRESSED")));
	}

	// Checks each type of weapon archetype being overlapped.
	// TODO: Create different sockets for each weapon archetype to hold enequipped (hips, back, etc.); Refactor code so that each Weapon Archetype will be casted/sorted through a function; Figure out how to cast lower-level weapons without all the casts(cutlass/flintlock/etc.)
	if (ABladeBase* OverlappingBlade = Cast<ABladeBase>(OverlappingItem))
	{
		OverlappingBlade->GetItemMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlappingBlade->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("Weapon_RSocket"));
	}
	else if (AGunBase* OverlappingGun = Cast<AGunBase>(OverlappingItem))
	{
		OverlappingGun->GetItemMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlappingGun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("Weapon_RSocket"));
	}
	else if (AExplosiveBase* OverlappingExplosive = Cast<AExplosiveBase>(OverlappingItem))
	{
		OverlappingExplosive->GetItemMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlappingExplosive->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("Weapon_RSocket"));
	}
	else 
	{
		return;
	}
}

// Health/Damage
void AMainPlayer::Damage(float DamageAmount)
{
	Health -= DamageAmount;

	if (Health <= 0.f)
	{
		Health = 0.f;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player Died")));
		}
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player Health: %f"), Health));
	}
}

void AMainPlayer::Heal(float HealAmount)
{
	Health += HealAmount;

	if (Health >= MaxHealth)
	{
		Health = MaxHealth;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Player Fully Healed!")));
		}
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Player Health: %f"), Health));
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Blades/BladeBase.h"
#include "Components/BoxComponent.h"



ABladeBase::ABladeBase()
{
	BladeCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BladeCollision"));
	BladeCollision->SetupAttachment(GetRootComponent());

	AttackSpeed = 15.f;
	bIsSharp = true;
	ResharpenTime = 5.f;
}

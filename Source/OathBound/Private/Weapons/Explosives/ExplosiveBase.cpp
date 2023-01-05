// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Explosives/ExplosiveBase.h"

AExplosiveBase::AExplosiveBase()
{
	ExplosiveCount = 0;
	ExplosiveCountMax = 3;

	DamageRadius = 30.f;
	ThrowDistance = 10.f;
}

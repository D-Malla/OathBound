// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Guns/GunBase.h"

AGunBase::AGunBase()
{
	ShootSpeed = 12.f;
	BulletCountMax = 3;
	BulletCount = 0;
	ReloadTime = 3.f;
}

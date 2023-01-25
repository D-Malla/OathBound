// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class UBoxComponent;
class USoundCue;
class USphereComponent;
class UTexture2D;

UCLASS()
class OATHBOUND_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// When PickupRadius sphere component is overlapped
	UFUNCTION()
	void OnRadiusSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// When PickupRadius sphere component stops overlapping
	UFUNCTION()
	void OnRadiusSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	USphereComponent* PickupRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	FString ID;

	UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	USoundCue* ItemPickupSound;

	//UPROPERTY(EditDefaultsOnly, Category = "Item | Base")
	//USoundCue* ItemDropSound;
public:
	FORCEINLINE UStaticMeshComponent* GetItemMesh() { return ItemMesh; }
	FORCEINLINE FString GetItemName() { return Name; }
	FORCEINLINE FString GetItemID() { return ID; }
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Banana.h"

ABanana::ABanana() {
 	static ConstructorHelpers::FObjectFinder<UStaticMesh> BananaBP(TEXT("/Game/Megascans/3D_Assets/Banana_tklkaixiw/S_Banana_tklkaixiw_lod0"));
	
	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	CollectableStaticMesh->SetStaticMesh(BananaBP.Object);
}

void ABanana::BeginPlay()
{
	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	UBoxComponent* CollectableBoxCollision = this->getBoxCollision();
	
	CollectableStaticMesh->SetWorldScale3D(FVector(2, 2, 2));
	CollectableStaticMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));

	CollectableBoxCollision->SetWorldScale3D(FVector(0.5f, 0.25f, 0.25f));

	Super::BeginPlay();
}
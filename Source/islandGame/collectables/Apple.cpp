// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

AApple::AApple() {
 	static ConstructorHelpers::FObjectFinder<UStaticMesh> AppleBP(TEXT("/Game/Megascans/3D_Assets/Red_Apple_tegqfetla/S_Red_Apple_tegqfetla_lod0"));

	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	CollectableStaticMesh->SetStaticMesh(AppleBP.Object);
}

void AApple::BeginPlay()
{
	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	UBoxComponent* CollectableBoxCollision = this->getBoxCollision();
	
	CollectableStaticMesh->SetWorldScale3D(FVector(2, 2, 2));
	CollectableBoxCollision->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	Super::BeginPlay();
}
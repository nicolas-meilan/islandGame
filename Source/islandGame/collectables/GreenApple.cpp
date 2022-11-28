// Fill out your copyright notice in the Description page of Project Settings.


#include "GreenApple.h"

AGreenApple::AGreenApple() {
 	static ConstructorHelpers::FObjectFinder<UStaticMesh> GreenAppleBP(TEXT("/Game/Megascans/3D_Assets/Apple_td3nedtla/S_Apple_td3nedtla_lod0"));

	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	UBoxComponent* CollectableBoxCollision = this->getBoxCollision();

	CollectableStaticMesh->SetStaticMesh(GreenAppleBP.Object);

}

void AGreenApple::BeginPlay()
{
	UStaticMeshComponent* CollectableStaticMesh = this->getStaticMesh();
	UBoxComponent* CollectableBoxCollision = this->getBoxCollision();
	
	CollectableStaticMesh->SetWorldScale3D(FVector(2, 2, 2));
	CollectableBoxCollision->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	Super::BeginPlay();
}
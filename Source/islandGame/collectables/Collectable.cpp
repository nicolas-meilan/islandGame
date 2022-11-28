// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"

ACollectable::ACollectable() {
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);
}

UBoxComponent* ACollectable::getBoxCollision() {
	return BoxCollision;
}

UStaticMeshComponent* ACollectable::getStaticMesh() {
	return StaticMesh;
}

float ACollectable::getSpeedRotation() {
	return SpeedRotation;
}

void ACollectable::setSpeedRotation(float speed) {
	SpeedRotation = speed;
}

void ACollectable::BeginPlay() {
	Super::BeginPlay();
	
	FScriptDelegate DelegateSibscriber;
	DelegateSibscriber.BindUFunction(this, "OnPlayerCollision");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSibscriber);

}


void ACollectable::OnPlayerCollision()
{
	if (!canCollect) return;

	Destroy();
}

void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator CurrentRotation = GetActorRotation();

	CurrentRotation.Add(0.f, DeltaTime * SpeedRotation, 0.f);
	SetActorRotation(CurrentRotation);
}

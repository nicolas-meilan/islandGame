// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Collectable.generated.h"

UCLASS()
class ISLANDGAME_API ACollectable : public AActor
{
	GENERATED_BODY()

public:	
	ACollectable();

	UStaticMeshComponent* getStaticMesh();
	UBoxComponent* getBoxCollision();

	float getSpeedRotation();
	void setSpeedRotation(float speed);

	UFUNCTION()
	void OnPlayerCollision();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
	bool canCollect = true;

	UPROPERTY(EditAnywhere)
	float SpeedRotation = 200.f;
};

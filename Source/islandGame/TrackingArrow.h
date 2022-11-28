// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "TrackingArrow.generated.h"

UCLASS()
class ISLANDGAME_API ATrackingArrow : public AActor
{
	GENERATED_BODY()

public:	
	ATrackingArrow();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	AActor* getClosestTrackActor();
	FRotator getRotationToActor(AActor* actor);
	void attachToActor();

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	UClass* ActorClassToTracking;

	UPROPERTY(EditAnywhere)
	UClass* ActorClassToBeAttached;


	AActor* ActorToBeAttached;

	UPROPERTY(EditAnywhere)
	float deltaAttachX = 0.f;
	UPROPERTY(EditAnywhere)
	float deltaAttachY = 0.f;
	UPROPERTY(EditAnywhere)
	float deltaAttachZ = 0.f;
};

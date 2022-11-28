// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Collectable.h"

#include "Apple.generated.h"

UCLASS()
class ISLANDGAME_API AApple : public ACollectable
{
	GENERATED_BODY()

public:	
	AApple();

protected:
	virtual void BeginPlay() override;

};

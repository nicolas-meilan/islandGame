// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Collectable.h"

#include "GreenApple.generated.h"

UCLASS()
class ISLANDGAME_API AGreenApple : public ACollectable
{
	GENERATED_BODY()

public:	
	AGreenApple();

protected:
	virtual void BeginPlay() override;
};

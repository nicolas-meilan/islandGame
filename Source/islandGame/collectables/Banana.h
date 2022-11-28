// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Collectable.h"

#include "Banana.generated.h"

UCLASS()
class ISLANDGAME_API ABanana : public ACollectable
{
	GENERATED_BODY()

public:	
	ABanana();

protected:
	virtual void BeginPlay() override;

};

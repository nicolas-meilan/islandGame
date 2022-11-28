// Copyright Epic Games, Inc. All Rights Reserved.

#include "islandGameGameMode.h"
#include "islandGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AislandGameGameMode::AislandGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MetaHumans/Chandra/BP_Custom_ThirdPerson"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

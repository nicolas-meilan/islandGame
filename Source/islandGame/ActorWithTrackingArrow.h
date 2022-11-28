#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActorWithTrackingArrow.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UActorWithTrackingArrow : public UInterface
{
	GENERATED_BODY()
};

class ISLANDGAME_API IActorWithTrackingArrow
{
	GENERATED_BODY()


public:
	virtual UStaticMeshComponent* getTrackingArrowComponent() {
		return nullptr;
	};
};

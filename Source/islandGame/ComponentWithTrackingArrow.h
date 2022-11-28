#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ComponentWithTrackingArrow.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UComponentWithTrackingArrow : public UInterface
{
	GENERATED_BODY()
};

class ISLANDGAME_API IComponentWithTrackingArrow
{
	GENERATED_BODY()


public:
	virtual UStaticMeshComponent* getTrackingArrowComponent() {
		return nullptr;
	};
};

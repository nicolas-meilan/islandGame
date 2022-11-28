#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "SpawnBox.generated.h"

UCLASS()
class ISLANDGAME_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawnBox();
	virtual void Tick(float DeltaTime) override;

	void setShouldSpawn(bool _shouldSpawn);
	bool spawnActor();

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void scheduleActorSpawn();
	void spawnActorSheduled();

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> ActorsClassToBeSpawned;

	UPROPERTY(EditAnywhere)
	float avgSpawnTime = 2.f;

	UPROPERTY(EditAnywhere)
	float randomSpawnTimeOffset = 1.f;

	bool shouldSpawn = true;

	FTimerHandle SpawnTimerHandle;
};

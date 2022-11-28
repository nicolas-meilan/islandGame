#include "SpawnBox.h"

ASpawnBox::ASpawnBox()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();

	if (shouldSpawn) {
		scheduleActorSpawn();
	}
}

void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}


void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASpawnBox::spawnActor() {
	bool spawned = false;
	if (!ActorsClassToBeSpawned.IsEmpty()) {
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		FVector spawnLocation = BoxBounds.Origin;
		spawnLocation.X += FMath::Abs(BoxBounds.BoxExtent.X * FMath::FRand());
		spawnLocation.Y += FMath::Abs(BoxBounds.BoxExtent.Y * FMath::FRand());
		spawnLocation.Z += FMath::Abs(BoxBounds.BoxExtent.Z * FMath::FRand());

		int numberOfActors = ActorsClassToBeSpawned.Num();
		int indexOfActorToRender = FMath::RandRange(0, numberOfActors - 1);
		TSubclassOf<AActor> currentActorToSpawn = ActorsClassToBeSpawned[indexOfActorToRender];
		if (currentActorToSpawn != NULL) {
			spawned = GetWorld()->SpawnActor(ActorsClassToBeSpawned[indexOfActorToRender], &spawnLocation) != nullptr;
		}
	}
	return spawned;
}

void ASpawnBox::scheduleActorSpawn() {
	float deltaToNextSpawn = avgSpawnTime + FMath::Abs(randomSpawnTimeOffset * FMath::FRand());

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnBox::spawnActorSheduled, deltaToNextSpawn, false);
}

void ASpawnBox::spawnActorSheduled() {
	bool spawned = spawnActor();
	if (!spawned) {
		// TODO ERROR LOG
		return;
	}

	if (shouldSpawn) {
		scheduleActorSpawn();
	}
}

void ASpawnBox::setShouldSpawn(bool _shouldSpawn) {
	bool prevShouldSpawn = shouldSpawn;
	shouldSpawn = _shouldSpawn;

	if (!prevShouldSpawn && shouldSpawn) {
		scheduleActorSpawn();
		return;
	}

	if (prevShouldSpawn && !shouldSpawn) {
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	}

}
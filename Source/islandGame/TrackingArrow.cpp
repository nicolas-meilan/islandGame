#include "TrackingArrow.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "ComponentWithTrackingArrow.h"

ATrackingArrow::ATrackingArrow() {
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrackingArrowStaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
}


void ATrackingArrow::BeginPlay() {
	Super::BeginPlay();

	StaticMesh->SetVisibility(false);
	attachToActor();
}

void ATrackingArrow::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	attachToActor();
	AActor* closestActor = getClosestTrackActor();

	if (!closestActor) {
		StaticMesh->SetVisibility(false);
		return;
	}

	StaticMesh->SetVisibility(true);
	FRotator newRotation = getRotationToActor(closestActor);
	SetActorRotation(newRotation);
}

AActor* ATrackingArrow::getClosestTrackActor() {
	TArray<AActor*> actorsToTrack;
	if (ActorClassToTracking != NULL) {
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClassToTracking, actorsToTrack);
	}

	if (!actorsToTrack.Num()) return nullptr;

	AActor* closestActor = actorsToTrack[0];
	float closestActorDistance = INFINITY;
	for (AActor* currentActor : actorsToTrack) {
		float distanceToActor = (GetActorLocation() - currentActor->GetActorLocation()).Size();
		if (closestActorDistance > distanceToActor) {
			closestActorDistance = distanceToActor;
			closestActor = currentActor;
		}
	}
	
	return closestActor;
}

FRotator ATrackingArrow::getRotationToActor(AActor* actor) {
	FRotator currentRotation = GetActorRotation();
	currentRotation.Roll = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), actor->GetActorLocation()).Roll;
	currentRotation.Yaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), actor->GetActorLocation()).Yaw;

	return currentRotation;
}

void ATrackingArrow::attachToActor() {
	if (ActorClassToBeAttached == NULL || ActorToBeAttached) return;

		ActorToBeAttached = UGameplayStatics::GetActorOfClass(GetWorld(), ActorClassToBeAttached);
		if (!ActorToBeAttached) return;

	FRotator currentRotation = GetActorRotation();
	FVector currentScale = GetActorScale3D();

	AttachToComponent(Cast<IComponentWithTrackingArrow>(ActorToBeAttached)->getTrackingArrowComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("TrackingArrow"));
	
	SetActorRotation(currentRotation);
	SetActorScale3D(currentScale);
}

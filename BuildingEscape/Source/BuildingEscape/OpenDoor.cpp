// Copyright Matt Rimler 2018

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

void UOpenDoor::CloseDoor()
{
	// Set door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));

}
	// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
		if (PressurePlate->IsOverlappingActor(ActorThatOpens))
		{
			OpenDoor();
			LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		}

	//check if time to close door
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}


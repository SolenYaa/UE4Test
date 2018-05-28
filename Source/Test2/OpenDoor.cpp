// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


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
    openActor = GetWorld()->GetFirstPlayerController()->GetPawn(); // 拿到操作的角色

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // 触发器 开门
    if (TriggerArea && openActor)
    {
        if (TriggerArea->IsOverlappingActor(openActor))
        {
            OpenDoor();
        }
        else
        {
            CloseDoor();
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("触发区域或角色为null"));
    }

}

void UOpenDoor::OpenDoor() {
    FRotator rotation = FRotator(0.0f, Angle, 0.0f);
    AActor *actor = GetOwner();
    actor->SetActorRotation(rotation);
}

void UOpenDoor::CloseDoor() {
    FRotator rotation = FRotator(0.0f, 0.0f, 0.0f);
    AActor *actor = GetOwner();
    actor->SetActorRotation(rotation);
}


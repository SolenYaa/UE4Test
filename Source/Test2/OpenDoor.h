// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST2_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // 开门角度  UPROPERTY(EditAnywhere) 标签让熟悉可在编辑器中调整
    UPROPERTY(EditAnywhere)
        float Angle = 0.0f;

    // 触发区域
    UPROPERTY(EditAnywhere)
        ATriggerVolume *TriggerArea = nullptr;

    // 触发角色
    UPROPERTY(EditAnywhere)
        AActor *openActor = nullptr;

private:
    void OpenDoor();
    void CloseDoor();
};

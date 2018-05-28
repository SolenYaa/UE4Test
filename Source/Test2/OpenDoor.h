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

    // ���ŽǶ�  UPROPERTY(EditAnywhere) ��ǩ����Ϥ���ڱ༭���е���
    UPROPERTY(EditAnywhere)
        float Angle = 0.0f;

    // ��������
    UPROPERTY(EditAnywhere)
        ATriggerVolume *TriggerArea = nullptr;

    // ������ɫ
    UPROPERTY(EditAnywhere)
        AActor *openActor = nullptr;

private:
    void OpenDoor();
    void CloseDoor();
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
FCollisionQueryParams QueryPar;

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
    // ��ײ���� ��ǩ�� �Ƿ�ϸ�ж� ��������
    QueryPar = FCollisionQueryParams("", false, GetOwner());
	
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (!PhysicsHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("�Ҳ����������"));
    }
    inputMouse = GetOwner()->FindComponentByClass<UInputComponent>();
    if (!inputMouse)
    {
        UE_LOG(LogTemp, Error, TEXT("�Ҳ���������"));
    }
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

//��ȡ�������
FVector UGrabber::GetLineStartPos() {
    FVector PlayerPos;
    FRotator PlayerRot;
    // ��ý�ɫ��λ�� �� ��ת���� ���ձ�������ֵ
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerPos, PlayerRot);
    return PlayerPos;
}

FVector UGrabber::GetLineEndPos() {
    FVector PlayerPos;
    FRotator PlayerRot;
    // �յ� = (��ɫλ�� + ����ת�Ƕ� �ĵ�λ����) * ����
    FVector LineTraceEndLocation = PlayerPos + PlayerRot.Vector() * Rech;
    return LineTraceEndLocation;
}

// ��ȡ������ײ
FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
    // ��������
    //DrawDebugLine(GetWorld(), PlayerPos, LineTraceEndLocation, FColor(255, 0, 0), false, 0.f, 0.f, 10.f);
    // �������������
    FHitResult hit;
    GetWorld()->LineTraceSingleByObjectType(
        hit,
        GetLineStartPos(),
        GetLineEndPos(),
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),   // �������� ����������
        QueryPar
    );
    AActor *actor = hit.GetActor();
    //if (actor)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("HIT NAME: %s"), *actor->GetName());
    //}
    return hit;
}


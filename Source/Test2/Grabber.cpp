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
    // 碰撞参数 标签？ 是否精细判断 忽略物体
    QueryPar = FCollisionQueryParams("", false, GetOwner());
	
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (!PhysicsHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("找不到物理组件"));
    }
    inputMouse = GetOwner()->FindComponentByClass<UInputComponent>();
    if (!inputMouse)
    {
        UE_LOG(LogTemp, Error, TEXT("找不到鼠标组件"));
    }
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

//获取射线起点
FVector UGrabber::GetLineStartPos() {
    FVector PlayerPos;
    FRotator PlayerRot;
    // 获得角色的位置 和 旋转方向 给空变量赋了值
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerPos, PlayerRot);
    return PlayerPos;
}

FVector UGrabber::GetLineEndPos() {
    FVector PlayerPos;
    FRotator PlayerRot;
    // 终点 = (角色位置 + 的旋转角度 的单位向量) * 长度
    FVector LineTraceEndLocation = PlayerPos + PlayerRot.Vector() * Rech;
    return LineTraceEndLocation;
}

// 获取射线碰撞
FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
    // 画出射线
    //DrawDebugLine(GetWorld(), PlayerPos, LineTraceEndLocation, FColor(255, 0, 0), false, 0.f, 0.f, 10.f);
    // 输出碰到的物体
    FHitResult hit;
    GetWorld()->LineTraceSingleByObjectType(
        hit,
        GetLineStartPos(),
        GetLineEndPos(),
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),   // 物体类型 带物理刚体的
        QueryPar
    );
    AActor *actor = hit.GetActor();
    //if (actor)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("HIT NAME: %s"), *actor->GetName());
    //}
    return hit;
}


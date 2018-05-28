// Fill out your copyright notice in the Description page of Project Settings.
// .cpp文件主要写逻辑
#include "Reporter.h"


// Sets default values for this component's properties
UReporter::UReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReporter::BeginPlay()           // ::代表作用域和所属关系
{
	Super::BeginPlay();
    AActor *Owner = GetOwner();       // 得到挂载脚本的对象 *代表指针
    FString Name = Owner->GetName();
    FVector Vector = Owner->GetActorLocation();
    UE_LOG(LogTemp, Warning, TEXT("Name: %s Location: %s"), *Name, *Vector.ToString());
    FRotator myRotation = FRotator(0.0f, 90.0f, 0.0f);    // 定义一个角度
    Owner->SetActorRotation(myRotation);                  // 旋转
}


// Called every frame
void UReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


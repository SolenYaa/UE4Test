// Fill out your copyright notice in the Description page of Project Settings.
// .cpp�ļ���Ҫд�߼�
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
void UReporter::BeginPlay()           // ::�����������������ϵ
{
	Super::BeginPlay();
    AActor *Owner = GetOwner();       // �õ����ؽű��Ķ��� *����ָ��
    FString Name = Owner->GetName();
    FVector Vector = Owner->GetActorLocation();
    UE_LOG(LogTemp, Warning, TEXT("Name: %s Location: %s"), *Name, *Vector.ToString());
    FRotator myRotation = FRotator(0.0f, 90.0f, 0.0f);    // ����һ���Ƕ�
    Owner->SetActorRotation(myRotation);                  // ��ת
}


// Called every frame
void UReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


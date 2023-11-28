// Fill out your copyright notice in the Description page of Project Settings.


#include "HubBB.h"


// Sets default values
AHubBB::AHubBB()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHubBB::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHubBB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHubBB::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


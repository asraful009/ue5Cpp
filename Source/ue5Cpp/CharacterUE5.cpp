// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterUE5.h"


// Sets default values
ACharacterUE5::ACharacterUE5()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterUE5::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterUE5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterUE5::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


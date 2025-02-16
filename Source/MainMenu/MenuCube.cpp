// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuCube.h"

// Sets default values
AMenuCube::AMenuCube() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMenuCube::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AMenuCube::Tick(float DeltaTime) {  
	Super::Tick(DeltaTime);
	// Rotates object
	if (rotate) {
		AddActorLocalRotation(FQuat(FRotator(pitch, yaw, roll)), false, 0, ETeleportType::None);
	}
}


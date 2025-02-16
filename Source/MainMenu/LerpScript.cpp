// Fill out your copyright notice in the Description page of Project Settings.


#include "LerpScript.h"

// Sets default values for this component's properties
ULerpScript::ULerpScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void ULerpScript::BeginPlay()
{
	Super::BeginPlay();
	timeElapsed = lerpTime + 1;
}


// Called every frame
void ULerpScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Update Lerp
	if (timeElapsed <= lerpTime) {
		tDivide = timeElapsed / lerpTime;
		lerpVector = Lerp(startPos, endPos, GetPerc(tDivide));
		timeElapsed += DeltaTime;
	} else {
		lerping = false;
	}
}

// Lerp Function
FVector ULerpScript::Lerp(FVector sValue, FVector eValue, float t) {
	return (sValue + (eValue - sValue) * t);
}

// Start a lerp if no lerp is currently in progress
void ULerpScript::StartLerp(FVector sValue, FVector eValue, float timeToTake) {
	if (!lerping) {
		timeElapsed = 0;
		lerpTime = timeToTake;
		startPos = sValue;
		endPos = eValue;
		lerping = true;
	}
}

// Ends a lerp in progress
void ULerpScript::ForceLerpEnd() {
	timeElapsed = lerpTime + 1;
	lerping = false;
}

// Gets the desired easing based on enum value
float ULerpScript::GetPerc(float t) {
	switch (ease) {
		case 0:
			return LinearEase(t);
		case 1:
			return QuadOutEase(t);
		case 2:
			return QuadInEase(t);
		case 3:
			return QuadInOutEase(t);
		default:
			return LinearEase(t);
	}
}

// Easings
float ULerpScript::LinearEase(float t) {
	return t;
}

float ULerpScript::QuadOutEase(float t) {
	return t * (2 - t);
}

float ULerpScript::QuadInEase(float t) {
	return t * t;
}

float ULerpScript::QuadInOutEase(float t) {
	if ((t *= 2) < 1) return 0.5 * t * t;
	return -0.5 * ((t -= 1) * (t - 2) - 1);
}

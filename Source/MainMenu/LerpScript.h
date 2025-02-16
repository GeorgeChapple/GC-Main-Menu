// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LerpScript.generated.h"

UENUM()
enum Easing {
	linear UMETA(DisplayName = "Linear Ease"),
	outQuad UMETA(DisplayName = "Out Quad Ease"),
	inQuad UMETA(DisplayName = "In Quad Ease"),
	inOutQuad UMETA(DisplayName = "In Out Quad Ease")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAINMENU_API ULerpScript : public UActorComponent
{
	GENERATED_BODY()
public:	
	ULerpScript();

protected:
	virtual void BeginPlay() override;
	float timeElapsed;
	float lerpTime;
	float tDivide;
	FVector startPos;
	FVector endPos;
	float GetPerc(float t);
	float LinearEase(float t);
	float QuadOutEase(float t);
	float QuadInEase(float t);
	float QuadInOutEase(float t);
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintReadWrite, Category = "Lerp")
	bool lerping;
	UPROPERTY(BlueprintReadWrite, Category = "Lerp")
	FVector lerpVector;
	UPROPERTY(BlueprintReadWrite, Category = "Lerp")
	TEnumAsByte<Easing> ease;
	UFUNCTION(BlueprintCallable, Category = "Lerp") 
	FVector Lerp(FVector sValue, FVector eValue, float t);
	UFUNCTION(BlueprintCallable, Category = "Lerp")
	void StartLerp(FVector sValue, FVector eValue, float timeToTake);
	UFUNCTION(BlueprintCallable, Category = "Lerp")
	void ForceLerpEnd();
};

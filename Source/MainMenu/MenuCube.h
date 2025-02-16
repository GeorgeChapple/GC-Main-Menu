// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MenuCube.generated.h"

UCLASS()
class MAINMENU_API AMenuCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMenuCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	bool rotate;
};

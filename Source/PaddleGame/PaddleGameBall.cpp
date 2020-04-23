// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleGameBall.h"

// Sets default values
APaddleGameBall::APaddleGameBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APaddleGameBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddleGameBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


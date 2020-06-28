// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PaddleGameGameMode.h"
#include "PaddleGameCharacter.h"
#include "PaddleGameBall.h"
#include "PaddleGameInstance.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"

void APaddleGameGameMode::BeginPlay()
{
	UWorld *world = GetWorld();

	if (world)  Ref_GameInstance = world->GetGameInstance<UPaddleGameInstance>();

}

APaddleGameGameMode::APaddleGameGameMode()
{
	// Set default pawn class to our character
	// DefaultPawnClass = APaddleGameCharacter::StaticClass();	
	Direction = 0.f;
	FPScore = 0;
	SPScore = 0;
}

void APaddleGameGameMode::UpdateScore(bool bIsAI)
{
	UWorld *world = GetWorld();
	if (bIsAI)
	{
		SPScore++;
		Direction = 1.f;
	}
	else
	{
		FPScore++;
		Direction = -1.f;
	}
	if (world)	world->GetTimerManager().SetTimer(DelaySpawningBall, this, &APaddleGameGameMode::SpawnBall, 1.f);
}

void APaddleGameGameMode::StartGame()
{
	Direction = FMath::Sign(FMath::RandRange(-1.f, 1.f));
	SpawnBall();
	if (Ref_GameInstance)
	{
		Ref_GameInstance->CallHUDWBP();
	}
}

void APaddleGameGameMode::SpawnBall()
{
	UWorld *world = GetWorld();
	if (world)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		Ref_GameBall = world->SpawnActor<APaddleGameBall>(
			APaddleGameBall::StaticClass(), 
			FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::OneVector), 
			SpawnParameters
		);

		if (Ref_GameBall) world->GetTimerManager().SetTimer(DelayBallMovement, this, &APaddleGameGameMode::SetVelocity, 0.2f);
	}
}

void APaddleGameGameMode::SetVelocity()
{
	if(Ref_GameBall) Ref_GameBall->ProjectileMovement->Velocity = FVector(Direction * BallSpeed, 0.f, 0.f).RotateAngleAxis(FMath::RandRange(-45.f, 45.f), FVector(0.f, 1.f, 0.f));
}

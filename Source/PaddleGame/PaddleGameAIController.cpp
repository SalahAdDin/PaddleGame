// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleGameAIController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "PaddleGameBall.h"
#include "PaddleGameCharacter.h"
#include "PaddleGameGameMode.h"

void APaddleGameAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld *world = GetWorld();
	// APaddleGameCharacter *PaddleCharacter = GetPawn<APaddleGameCharacter>();

	if (world)
	{
		Ref_Ball = world->GetAuthGameMode<APaddleGameGameMode>()->Ref_GameBall;
	}
	if (GetPawn() != nullptr)
	if (Ref_Ball != NULL)
	{
		/*if (Ref_Ball->GetVelocity().X < 0.0)
			PaddleCharacter->SetActorLocation(
				FMath::VInterpConstantTo(
					PaddleCharacter->GetActorLocation(), 
					FVector(-1440.f, 0.f, Ref_Ball->GetActorLocation().Z), 
					UGameplayStatics::GetWorldDeltaSeconds(world), PaddleCharacter->Speed)
			);*/
	}
	else
	{
		/*PaddleCharacter->SetActorLocation(
			FMath::VInterpConstantTo(
				PaddleCharacter->GetActorLocation(), 
				FVector(-1440.f, 0.f, 0.f), 
				UGameplayStatics::GetWorldDeltaSeconds(world), 
				PaddleCharacter->Speed)
		);*/
	}
}

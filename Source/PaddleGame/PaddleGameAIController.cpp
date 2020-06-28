// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleGameAIController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "PaddleGameBall.h"
#include "PaddleGameCharacter.h"
#include "PaddleGameGameMode.h"

/*
OnPossess  is called when the  controller possesses a pawn, this is when you know the controller  has a valid pawn;
if the pawn changes, OnPossess gets called again and change the pointer.
*/
void APaddleGameAIController::OnPossess(APawn * InPawn){
	Super::OnPossess(NewPawn);
	Ref_PaddleCharacter = GetPawn<APaddleGameCharacter>();
}


/*
Tick will then check if the pawn(Ref_Paddle...) is valid, if  it is, then will run its stuff;
we avoid to cast the pawn every tick.
*/
void APaddleGameAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld *world = GetWorld();

	if (world)
	{
		Ref_Ball = world->GetAuthGameMode<APaddleGameGameMode>()->Ref_GameBall;
	}
	if (Ref_PaddleCharacter)
		if (Ref_Ball != NULL)
		{
			if (Ref_Ball->GetVelocity().X < 0.0)
				Ref_PaddleCharacter->SetActorLocation(
					FMath::VInterpConstantTo(
						Ref_PaddleCharacter->GetActorLocation(),
						FVector(-1440.f, 0.f, Ref_Ball->GetActorLocation().Z),
						UGameplayStatics::GetWorldDeltaSeconds(world), Ref_PaddleCharacter->Speed));
		}
		else
		{
			Ref_PaddleCharacter->SetActorLocation(
				FMath::VInterpConstantTo(
					Ref_PaddleCharacter->GetActorLocation(),
					FVector(-1440.f, 0.f, 0.f),
					UGameplayStatics::GetWorldDeltaSeconds(world),
					Ref_PaddleCharacter->Speed));
		}
}

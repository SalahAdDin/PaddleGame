// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/GameModeBase.h"
#include "PaddleGameGameMode.generated.h"

class APaddleGameBall;
class UPaddleGameInstance;

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of PaddleGameCharacter
 */
UCLASS(minimalapi)
class APaddleGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

	FTimerHandle DelaySpawningBall;
	FTimerHandle DelayBallMovement;

	float Direction;
	
	

	UPROPERTY()
	UPaddleGameInstance* Ref_GameInstance = nullptr;

	void BeginPlay() override;

public:
	APaddleGameGameMode();

	UPROPERTY(BlueprintReadOnly, Category = Internal)
		APaddleGameBall* Ref_GameBall = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Behaviour)
		float BallSpeed;


	UPROPERTY(BlueprintReadOnly, Category = Score)
		int FPScore;

	UPROPERTY(BlueprintReadOnly, Category = Score)
		int SPScore;

	UFUNCTION(BlueprintCallable, Category = Behavior)
		void UpdateScore(bool bIsAI);

	UFUNCTION(BlueprintCallable, Category = Behavior)
		void StartGame();

	UFUNCTION()
		void SpawnBall();

	UFUNCTION()
		void SetVelocity();

};

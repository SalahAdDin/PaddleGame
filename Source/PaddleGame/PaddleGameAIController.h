// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PaddleGameAIController.generated.h"

class APaddleGameBall;
/**
 * 
 */
UCLASS()
class PADDLEGAME_API APaddleGameAIController : public AAIController
{
	GENERATED_BODY()

	APaddleGameBall* Ref_Ball;


public:
	virtual void Tick(float DeltaTime) override;
	
};

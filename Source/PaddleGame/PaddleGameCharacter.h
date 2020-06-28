// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Math/Color.h"
#include "PaddleGameCharacter.generated.h"

class UTextRenderComponent;

/**
 * This class is the default character for PaddleGame, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config=Game)
class APaddleGameCharacter : public APaperCharacter
{
	GENERATED_BODY()

protected:
	/** Called for side to side input */
	void MoveFordward(float Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	APaddleGameCharacter();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Characteristic)
		FLinearColor Color;

	UPROPERTY(EditDefaultsOnly, Category = Characteristic)
		float Speed;


};

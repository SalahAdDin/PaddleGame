// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PaddleGameGameMode.h"
#include "PaddleGameCharacter.h"

APaddleGameGameMode::APaddleGameGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APaddleGameCharacter::StaticClass();	
}

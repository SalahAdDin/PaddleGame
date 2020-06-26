// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PaddleGameInstance.generated.h"


class UUserWidget;

/**
 *
 */
UCLASS()
class PADDLEGAME_API UPaddleGameInstance : public UGameInstance
{
	GENERATED_BODY()

	TSubclassOf<UUserWidget> HUDWidgetClass;

public:
	UPaddleGameInstance();

	UPROPERTY()
		UUserWidget *Ref_HUD = nullptr;

	UFUNCTION(BlueprintCallable, Category = "User Interface")
		void CallHUDWBP();


};

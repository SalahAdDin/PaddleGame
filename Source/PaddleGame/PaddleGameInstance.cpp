// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

UPaddleGameInstance::UPaddleGameInstance()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidget(TEXT("/Game/Blueprints/WBP_HUD"));
	if (HUDWidget.Class != NULL) HUDWidgetClass = HUDWidget.Class;
}

void UPaddleGameInstance::CallHUDWBP()
{
	if (Ref_HUD != NULL) Ref_HUD->RemoveFromParent();

	Ref_HUD = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(this, 0), HUDWidgetClass);

	Ref_HUD->AddToViewport();
}

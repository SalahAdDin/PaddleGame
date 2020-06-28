// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleGameBall.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/Material.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APaddleGameBall::APaddleGameBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Ball"));
	RootComponent = SM_Ball; // ->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));
	static ConstructorHelpers::FObjectFinder<UMaterial>SphereMaterialAsset(TEXT("/Game/Materials/M_Ball"));
	if (SphereMeshAsset.Object != nullptr)
		SM_Ball->SetStaticMesh(SphereMeshAsset.Object);
	if (SphereMaterialAsset.Object != nullptr)
		SM_Ball->SetMaterial(0, SphereMaterialAsset.Object);
	SM_Ball->SetCollisionProfileName("BlockAll");

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.f;
	ProjectileMovement->Friction = 0.f;
	ProjectileMovement->Velocity = FVector(0.f, 0.f, 0.f);
	ProjectileMovement->SetPlaneConstraintNormal(FVector(0.f, 1.f, 0.f));
	ProjectileMovement->bConstrainToPlane = true;

}


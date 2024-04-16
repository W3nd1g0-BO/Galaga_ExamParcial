// Fill out your copyright notice in the Description page of Project Settings.


#include "Galaga_USFX_L02Bomba.h"
#include "TimerManager.h"
#include "NaveEnemiga.h"

AGalaga_USFX_L02Bomba::AGalaga_USFX_L02Bomba()
{
	

	ProjectileMesh->SetWorldScale3D(FVector(3.0f));

	ProjectileMovement->ProjectileGravityScale = 1.f;
};

void AGalaga_USFX_L02Bomba::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()!=nullptr)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGalaga_USFX_L02Bomba::explosionBomba, 3.0f, false);
	}
}

void AGalaga_USFX_L02Bomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



void AGalaga_USFX_L02Bomba::explosionBomba()
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);

	for  (AActor* nave : OverlappingActors)
	{
		if (nave->IsA(ANaveEnemiga::StaticClass()))
		{
			ANaveEnemiga* naveEnemiga = Cast<ANaveEnemiga>(nave);
			naveEnemiga->Destroy();
		}
	}

	this->Destroy();
}
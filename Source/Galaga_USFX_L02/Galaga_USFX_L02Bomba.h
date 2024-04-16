// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Galaga_USFX_L02Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Galaga_USFX_L02Bomba.generated.h"


class ANaveEnemiga;

UCLASS()
class GALAGA_USFX_L02_API AGalaga_USFX_L02Bomba : public AGalaga_USFX_L02Projectile
{
	GENERATED_BODY()
	
	AGalaga_USFX_L02Bomba();
protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
	void explosionBomba();
	FTimerHandle TimerHandle;
};

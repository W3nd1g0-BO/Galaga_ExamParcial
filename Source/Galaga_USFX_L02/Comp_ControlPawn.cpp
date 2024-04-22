// Fill out your copyright notice in the Description page of Project Settings.


#include "Comp_ControlPawn.h"
#include "Galaga_USFX_L02Bomba.h"
#include "Galaga_USFX_L02Pawn.h"
#include "Kismet/GameplayStatics.h"

class AGalaga_USFX_L02Pawn;
class AGalaga_USFX_L02Bomba;

// Sets default values for this component's properties
UComp_ControlPawn::UComp_ControlPawn()
{
	
}


// Called when the game starts
void UComp_ControlPawn::BeginPlay()
{
	Jugador = Cast<AGalaga_USFX_L02Pawn>(GetOwner());
}


// Called every frame
void UComp_ControlPawn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UComp_ControlPawn::SpawnBomb()
{
	int bomb = Jugador->GetbombDisponibles();

	if (Jugador != nullptr) 
	{
		if (bomb != 0 )
		{
			const FVector SpawnLocation = GetOwner()->GetActorLocation();
			const FRotator SpawnRotation = GetOwner()->GetActorRotation();

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AGalaga_USFX_L02Bomba>(SpawnLocation, SpawnRotation);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bomba lanzada"));
				Jugador->SetbombDisponibles(Jugador->GetbombDisponibles() - 1);
			}
		}
	}
}
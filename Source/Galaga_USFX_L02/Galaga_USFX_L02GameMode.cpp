// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L02GameMode.h"
#include "Galaga_USFX_L02Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "Capsulas.h"


AGalaga_USFX_L02GameMode::AGalaga_USFX_L02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L02Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L02GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	limiteMapa = FBox(FVector(-2000.0f, -2000.0f, 0.0f), FVector(2000.0f, 2000.0f, 350.0f));

	FVector ubicacionInicialNavesEnemigas = FVector(0.0f, 0.0f, 300.0f);
	FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionCapsula = FVector(0.0f, 0.0f, 300.0f);
	FRotator rotacionCapsula = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
	
		for (int i = 0; i < 15; i++) {
			ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionActualNaveEnemiga, rotacionNave);
			//TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
			NaveEnemigaCazaActual->SetNombre("nave enemiga caza " + FString::FromInt(i));
			TANavesEnemigas.Add(NaveEnemigaCazaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionActualNaveEnemiga);

			ubicacionActualNaveEnemiga = FMath::RandPointInBox(limiteMapa);
			ubicacionActualNaveEnemiga.Z = 300.0f;
		}

		
		for (int j = 0; j < 15; j++) {
			
			ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionActualNaveEnemiga, rotacionNave);
			//TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
			NaveEnemigaTransporteActual->SetNombre("nave enemiga transporte" + FString::FromInt(j));
			TANavesEnemigas.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionActualNaveEnemiga);

			ubicacionActualNaveEnemiga = FMath::RandPointInBox(limiteMapa);
			ubicacionActualNaveEnemiga.Z = 300.0f;
		}

		for (int k = 0; k < 5; k++)
		{
			ACapsulas* CapsulaActual = World->SpawnActor<ACapsulas>(ubicacionCapsula, rotacionCapsula);
			TACapsulas.Add(CapsulaActual);
            ubicacionCapsula = FMath::RandPointInBox(limiteMapa);
			ubicacionCapsula.Z = 300.0f;
		};
		
		//FTimerHandle FTHVisualizacionPosicionesNavesEnemigas;

		//GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFX_L02GameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);
		
	}

}

void AGalaga_USFX_L02GameMode::MostrarPosicionesNavesEnemigas()
{
	for (auto ElementoActual : TMPosicionesNavesEnemigas) {
		ANaveEnemiga* naveEnemigaActual = ElementoActual.Key;
		FVector posicionActualNaveEnemiga = ElementoActual.Value;
		FString mensaje = "La nave " + naveEnemigaActual->GetNombre() + " esta en la posicion> " + posicionActualNaveEnemiga.ToString();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, mensaje);

			/*FString mensaje = "Nombre NaveEnemiga: " + Clave->GetNombre() + " Posicion NaveEnemiga: " + Valor.ToString();
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mensaje);*/

		}

		TMPosicionesNavesEnemigas[naveEnemigaActual] = naveEnemigaActual->GetActorLocation();
	}
}
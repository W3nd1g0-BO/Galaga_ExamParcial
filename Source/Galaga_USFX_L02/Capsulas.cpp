// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsulas.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Galaga_USFX_L02Pawn.h"

// Sets default values
ACapsulas::ACapsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creacion de la malla de la capsula
	meshCapsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsulaMesh"));
	meshCapsula->SetupAttachment(RootComponent);
	RootComponent = meshCapsula;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	meshCapsula->SetStaticMesh(mesh.Object);

	meshCapsula->SetCollisionProfileName(TEXT("OverlapAll"));
}

// Called when the game starts or when spawned
void ACapsulas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


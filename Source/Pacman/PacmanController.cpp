// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanController.h"
#include "PacmanPawn.h"

void APacmanController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction<FMoveToDirection>("MoveUp", IE_Pressed, this, &APacmanController::MoveToDirection, FVector::UpVector);
	InputComponent->BindAction<FMoveToDirection>("MoveDown", IE_Pressed, this, &APacmanController::MoveToDirection, FVector::DownVector);
	InputComponent->BindAction<FMoveToDirection>("MoveLeft", IE_Pressed, this, &APacmanController::MoveToDirection, FVector::LeftVector);
	InputComponent->BindAction<FMoveToDirection>("MoveRight", IE_Pressed, this, &APacmanController::MoveToDirection, FVector::RightVector);
}

APacmanPawn* APacmanController::GetPacmanPawn() const
{
	return Cast<APacmanPawn>(GetPawn());
}

void APacmanController::MoveToDirection(FVector dir)
{
	if (GetPacmanPawn() != nullptr) {
		GetPacmanPawn()->SetDirection(dir);
	}
}


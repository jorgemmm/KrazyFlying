// Copyright Epic Games, Inc. All Rights Reserved.

#include "KrazyFlyingGameMode.h"
#include "KrazyFlyingPawn.h"

AKrazyFlyingGameMode::AKrazyFlyingGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AKrazyFlyingPawn::StaticClass();
}

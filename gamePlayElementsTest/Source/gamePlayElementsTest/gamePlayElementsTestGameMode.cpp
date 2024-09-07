// Copyright Epic Games, Inc. All Rights Reserved.

#include "gamePlayElementsTestGameMode.h"
#include "gamePlayElementsTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AgamePlayElementsTestGameMode::AgamePlayElementsTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

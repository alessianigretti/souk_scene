// Copyright Epic Games, Inc. All Rights Reserved.

#include "souk_sceneGameMode.h"
#include "souk_sceneCharacter.h"
#include "UObject/ConstructorHelpers.h"

Asouk_sceneGameMode::Asouk_sceneGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

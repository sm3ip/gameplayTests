// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"

// Sets default values
AMyTestPawn::AMyTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMyTestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	/*
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			
			if (!InputMapping.IsNull())
			{
				InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
			}
		}
	}
	*/
	// get the player controller
	APlayerController* PC = Cast<APlayerController>(GetController());

	// get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	// clear existing mapping and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// binding input actions to their corresponding functions
	Input->BindAction(inputToCrouch, ETriggerEvent::Triggered, this, &AMyTestPawn::CrouchAction);
	Input->BindAction(inputToDive, ETriggerEvent::Triggered, this, &AMyTestPawn::DiveAction);
	Input->BindAction(inputToJump, ETriggerEvent::Triggered, this, &AMyTestPawn::JumpAction);
	Input->BindAction(inputToLook, ETriggerEvent::Triggered, this, &AMyTestPawn::LookAction);
	Input->BindAction(inputToMove, ETriggerEvent::Triggered, this, &AMyTestPawn::MoveAction);

}



void AMyTestPawn::CrouchAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	bool BoolValue = Value.Get<bool>();
}

void AMyTestPawn::MoveAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	FVector2D AxisVal = Value.Get<FVector2D>();
}

void AMyTestPawn::LookAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	FVector2D AxisVal = Value.Get<FVector2D>();
}

void AMyTestPawn::JumpAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	bool BoolValue = Value.Get<bool>();
}

void AMyTestPawn::DiveAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	float FloatValue = Value.Get<float>();
}



 
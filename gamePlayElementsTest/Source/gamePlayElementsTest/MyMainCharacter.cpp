// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"

// Sets default values
AMyMainCharacter::AMyMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up base values for various variables
	TArmLength = 300.0f;
	sockOffset = FVector(-4.0f, 0.0f, 31.0f);
	RelRotation = FRotator(0.0f, -10.0f, 0.0f);
	PlayerSpeed = 10.0f;

	// camera bullshit
	boomArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("boomArm"));
	boomArm->SetupAttachment(this->GetCapsuleComponent());

	// boom arm rotation not affected by player rotation
	boomArm->SetUsingAbsoluteRotation(true);
	boomArm->bDoCollisionTest = false;
	boomArm->TargetArmLength = TArmLength;
	boomArm->SocketOffset = sockOffset;
	boomArm->SetRelativeRotation(RelRotation);

	//camera creation
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	camera->SetupAttachment(boomArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void AMyMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyMainCharacter::CrouchAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	bool BoolValue = Value.Get<bool>();
	if (BoolValue)
	{
		boomArm->TargetArmLength = 1000.0f;
	}
	else {
		boomArm->TargetArmLength = TArmLength;
	}
}

void AMyMainCharacter::MoveAction(const FInputActionValue& Value)
{
	//gets the value, we'll do cool stuff later
	FVector2D AxisVal = Value.Get<FVector2D>();
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red,(TEXT("Forward Vect %s"), *this->GetActorForwardVector().ToString()));
	//print(this->GetActorForwardVector());
	AddMovementInput(this->GetActorForwardVector() * AxisVal.Y * PlayerSpeed);
	AddMovementInput(this->GetActorRightVector() * AxisVal.X * PlayerSpeed);
}

void AMyMainCharacter::LookAction(const FInputActionValue& Value)
{
}

void AMyMainCharacter::JumpAction(const FInputActionValue& Value)
{
}

void AMyMainCharacter::DiveAction(const FInputActionValue& Value)
{
}

// Called every frame
void AMyMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
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
	Input->BindAction(inputToCrouch, ETriggerEvent::Triggered, this, &AMyMainCharacter::CrouchAction);
	Input->BindAction(inputToDive, ETriggerEvent::Triggered, this, &AMyMainCharacter::DiveAction);
	Input->BindAction(inputToJump, ETriggerEvent::Triggered, this, &AMyMainCharacter::JumpAction);
	Input->BindAction(inputToLook, ETriggerEvent::Triggered, this, &AMyMainCharacter::LookAction);
	Input->BindAction(inputToMove, ETriggerEvent::Triggered, this, &AMyMainCharacter::MoveAction);

}


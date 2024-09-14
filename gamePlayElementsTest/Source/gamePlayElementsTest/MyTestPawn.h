// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "MyTestPawn.generated.h"

UCLASS()
class GAMEPLAYELEMENTSTEST_API AMyTestPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTestPawn();
	// capsule body todo maybe try blueprintreadwrite
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "body", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* body;

	// camera components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* boomArm;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	// input methods
	void CrouchAction(const FInputActionValue& Value);
	void MoveAction(const FInputActionValue& Value);
	void LookAction(const FInputActionValue& Value);
	void JumpAction(const FInputActionValue& Value);
	void DiveAction(const FInputActionValue& Value);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	

	// input actions
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	//UInputMappingContext* inputMappingContext;
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToDive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToCrouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToLook;

};

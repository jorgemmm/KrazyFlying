// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoShip.generated.h"

UCLASS()
class KRAZYFLYING_API AGoShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/** Bound to the thrust axis */
	//void ThrustInput(float Val);

	/** Bound to the vertical axis */
	void MoveUpX(float Val);

	/** Bound to the horizontal axis */
	//void MoveRightInput(float Val);


	/** Current forward speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingShip", meta = (AllowPrivateAccess = "true"))
	float CurrentForwardSpeed;

	//Vbles que deben replicarse

	/** How quickly pawn can steer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingShip", meta = (AllowPrivateAccess = "true"))
		float TurnSpeed;

	//fin Vbles que deben replicarse

	/** Current yaw speed */
	float CurrentYawSpeed;

	/** Current pitch speed */
	float CurrentPitchSpeed;

	/** Current roll speed */
	float CurrentRollSpeed;


	



	/**-1 para iinvertir controles*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingShip", meta = (AllowPrivateAccess = "true"))
		int32 InversionControl = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

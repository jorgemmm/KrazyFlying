//@Autor Vicagent


#include "GoShip.h"


AGoShip::AGoShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//this propertyMust be replicated to work out in multiplayer online
	TurnSpeed = 50.f;
	CurrentForwardSpeed = 500.f;
}


void AGoShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGoShip::FireShot(FVector FireDirection)
{
    //TODO: 
    //Fire Mechanics
}


void AGoShip::Tick(float DeltaTime)
{
	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime, 0.f, 0.f);

	// Move plan forwards (with sweep so we stop when we collide with things)
	AddActorLocalOffset(LocalMove, true);

	// Calculate change in rotation this frame
	FRotator DeltaRotation(0, 0, 0);
	DeltaRotation.Pitch = CurrentPitchSpeed * DeltaTime;
	//DeltaRotation.Yaw = CurrentYawSpeed * DeltaTime;
	//DeltaRotation.Roll = CurrentRollSpeed * DeltaTime;
	
	// Rotate plane
	AddActorLocalRotation(DeltaRotation);

	Super::Tick(DeltaTime);
}


// Called to bind functionality to input
void AGoShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUpX", this, &AGoShip::MoveUpX);

}

void AGoShip::MoveUpX(float Val)
{
	// Target pitch speed is based in input
	const float TargetPitchSpeed = (Val * TurnSpeed* InversionControl);// * -1.f);

	// When steering, we decrease pitch slightly
	//TargetPitchSpeed += (FMath::Abs(CurrentYawSpeed) * -0.2f);

	// Smoothly interpolate to target pitch speed
	CurrentPitchSpeed = FMath::FInterpTo(CurrentPitchSpeed, TargetPitchSpeed, GetWorld()->GetDeltaSeconds(), 2.f);

}




/*
  CharonMovement.h - Library for movements of a specific BOEbot: "Charon"
*/


// Description File of This Library
#include "CharonMovement.h"

// Servo library and its description
#include "Servo.h"
#include <Servo.h>

//Constructor Function
Motion::Motion(Servo rightMotor, Servo leftMotor)
{
  LeftWheel = leftMotor;
  RightWheel = rightMotor;
  Stop = 1500;
  LeftFullClock = 1388;
  LeftFullAnti = 1600;
  RightFullClock = 1404;
  RightFullAnti = 1593.5;
  LeftHalfClock = 1465;
  LeftHalfAnti = 1537;
  RightHalfClock = 1461.5;
  RightHalfAnti = 1530;
}

// Public Methods
void Motion::StayStill(void)
{
    RightWheel.writeMicroseconds(Stop);
    LeftWheel.writeMicroseconds(Stop);
    return;
}

void Motion::Forward(void)
{
    RightWheel.writeMicroseconds(RightFullClock);
    LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Motion::Backward(void)
{
    RightWheel.writeMicroseconds(RightFullAnti);
    LeftWheel.writeMicroseconds(LeftFullClock);
}

void Motion::LeftTurn(void)
{
    RightWheel.writeMicroseconds(RightFullClock);
    LeftWheel.writeMicroseconds(LeftFullClock);
}

void Motion::RightTurn(void)
{
    RightWheel.writeMicroseconds(RightFullAnti);
    LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Motion::ForwardLeft(void)
{
    RightWheel.writeMicroseconds(RightFullClock);
    LeftWheel.writeMicroseconds(LeftHalfAnti);
}

void Motion::ForwardRight(void)
{
    RightWheel.writeMicroseconds(RightHalfClock);
    LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Motion::BackwardLeft(void)
{
    RightWheel.writeMicroseconds(RightFullAnti);
    LeftWheel.writeMicroseconds(LeftHalfClock);
}

void Motion::BackwardRight(void)
{
    RightWheel.writeMicroseconds(RightHalfAnti);
    LeftWheel.writeMicroseconds(LeftFullClock);
}

void Motion::Attach(int rightPin, int leftPin)
{
    RightWheel.attach(rightPin);
    LeftWheel.attach(leftPin);
}

// Private Methods
// This library has no private methods.



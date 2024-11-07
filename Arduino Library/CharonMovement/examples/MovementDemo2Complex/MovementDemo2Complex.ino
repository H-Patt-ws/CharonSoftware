// Movement Demo 2 - Complex
// by Hope Patterson

// Demostrates half of Charon's movement functions: The complex half
// These motions are: forward with a right bearing, forward with a left bearing,
// backward with a right bearing, backward with a left bearing

// Created 4 November 2024

#include <CharonMovement.h>
#include <Servo.h>

Servo Right;
Servo Left;
Motion Move = Motion(Right, Left);

void setup()
{
  Move.Attach(12, 13);
}

void loop()
{
delay(5000);
Move.ForwardLeft();
delay(3000);
Move.ForwardRight();
delay(3000);
Move.BackwardRight();
delay(3000);
Move.BackwardLeft();
delay(3000);
Move.StayStill();
}


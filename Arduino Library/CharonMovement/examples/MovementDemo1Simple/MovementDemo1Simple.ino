// Movement Demo 1 - Simple
// by Hope Patterson

// Demostrates half of Charon's movement functions: The simple half
// These motions are: forward, backward, left and right

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
Move.StayStill();
delay(5000);
//Forward
Move.Forward();
delay(1000);
Move.StayStill();
delay(1000);
//Backward
Move.Backward();
delay(1000);
Move.StayStill();
delay(1000);
//Spin Right
Move.RightTurn();
delay(2000);
Move.StayStill();
delay(1000);
//Spin Left
Move.LeftTurn();
delay(2000);
Move.StayStill();
}


/*
  CharonMovement.h - Library for movements of a specific BOEbot: "Charon" - description
*/

// ensure library description is only included once
#ifndef CharonMovement_h
#define CharonMovement_h

// description of Servo library
#include "Servo.h"

// library interface description
class Motion
{
  //Public attributes and methods
  public:
    Motion(Servo, Servo);
    void StayStill(void);
    void Forward(void);
    void Backward(void);
    void LeftTurn(void);
    void RightTurn(void);
    void ForwardLeft(void);
    void ForwardRight(void);
    void BackwardLeft(void);
    void BackwardRight(void);
    void Attach(int, int);

  // Private attributes and methods
  private:
    int Stop;
    int LeftFullClock;
    int LeftFullAnti;
    int RightFullClock;
    int RightFullAnti;
    float LeftHalfClock;
    float LeftHalfAnti;
    float RightHalfClock;
    float RightHalfAnti;
    Servo RightWheel;
    Servo LeftWheel;
};

#endif


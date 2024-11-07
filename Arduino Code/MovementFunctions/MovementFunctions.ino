#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;

//Stop Signal
int Stop = 1500;

// Full Speed Signals
int LeftFullClock = 1395;
int LeftFullAnti = 1604;
int RightFullClock = 1375;
int RightFullAnti = 1618;

//Half Speed Signals
float LeftHalfClock = 1452.75;
float LeftHalfAnti = 1541.5;
float RightHalfClock = 1451.75;
float RightHalfAnti = 1545;

//Stay Still: Both wheels stop
void StayStill(){
  RightWheel.writeMicroseconds(Stop);
  LeftWheel.writeMicroseconds(Stop);
}

//Forward: Right wheel clockwise, left anticlockwise, both 1x speed
void Forward(){
  RightWheel.writeMicroseconds(RightFullClock);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

//Backward: Right wheel anticlockwise, left clockwise, both 1x speed
void Backward(){
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftFullClock);
}

//Left Turn: Both wheels clockwise 1x speed 
void LeftTurn(){
  RightWheel.writeMicroseconds(RightFullClock);  
  LeftWheel.writeMicroseconds(LeftFullClock);
}

//Right Turn: Both wheels anticlockwise 1x speed
void RightTurn(){ 
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

//Forward bear left: Right wheel clockwise 1x speed, left wheel anticlockwise 0.5x speed
void ForwardLeft(){
  RightWheel.writeMicroseconds(RightFullClock);
  LeftWheel.writeMicroseconds(LeftHalfAnti);
}

//Forward bear right: Right wheel clockwise 0.5x speed, left wheel anticlockwise 1x speed 
void ForwardRight(){
  RightWheel.writeMicroseconds(RightHalfClock);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

//Backward bear left: Right wheel anticlockwise x1 speed, left wheel clockwise 0.5x speed
void BackwardLeft(){
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftHalfClock);
}

//Backward bear right: Right wheel anticlockwise 0.5x speed, left wheel clockwise 1x speed
void BackwardRight(){
  RightWheel.writeMicroseconds(RightHalfAnti);
  LeftWheel.writeMicroseconds(LeftFullClock);
}

void setup() {
RightWheel.attach(12); //the right wheel is wired to pin 12
LeftWheel.attach(13); //the left wheel is wired to pin 13

}
void loop() {
}

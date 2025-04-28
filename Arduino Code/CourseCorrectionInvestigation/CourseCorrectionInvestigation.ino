#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;
//Stop Signal
int Stop = 1500;

// Full Speed Signals
int LeftFullClock = 1388;
int LeftFullAnti = 1600;
int RightFullClock = 1404;
int RightFullAnti = 1593.5;

//Half Speed Signals
float LeftHalfClock = 1465;
float LeftHalfAnti = 1537;
float RightHalfClock = 1461.5;
float RightHalfAnti = 1530;

void LeftTest(int direction){
  delay(3000);  
  LeftWheel.writeMicroseconds(direction);
  delay(10000);
  LeftWheel.writeMicroseconds(1500);
}

void RightTest(int direction){
  delay(3000);  
  RightWheel.writeMicroseconds(direction);
  delay(10000);
  RightWheel.writeMicroseconds(1500);
}

void Forward(){
  RightWheel.writeMicroseconds(RightFullClock);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Backward(){
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftFullClock);
}

void StayStill(){
  RightWheel.writeMicroseconds(Stop);
  LeftWheel.writeMicroseconds(Stop);
}

void FullMovementTest(){
 delay(5000);
 RightWheel.writeMicroseconds(RightFullClock);
 LeftWheel.writeMicroseconds(LeftFullAnti);
 delay(10000);
 RightWheel.writeMicroseconds(Stop);
 LeftWheel.writeMicroseconds(Stop);
 delay(3000);
 RightWheel.writeMicroseconds(RightFullAnti);
 LeftWheel.writeMicroseconds(LeftFullClock);
 delay(10000);
 RightWheel.writeMicroseconds(Stop);
 LeftWheel.writeMicroseconds(Stop);
}

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);

}

void loop() {

RightTest(RightHalfAnti);

}

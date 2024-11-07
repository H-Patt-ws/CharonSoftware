//This code will cause the BOEbot to turn RIGHT for as long as it is on.

#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;
int FullClock = 1300; //write value for full speed clockwise rotation
int FullAnti = 1700; //write value for full speed anticlockwise rotation

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);
}

void loop() {
//In order to turn right, both wheels must turn anticlockwise
RightWheel.writeMicroseconds(FullAnti);
LeftWheel.writeMicroseconds(FullAnti);
}

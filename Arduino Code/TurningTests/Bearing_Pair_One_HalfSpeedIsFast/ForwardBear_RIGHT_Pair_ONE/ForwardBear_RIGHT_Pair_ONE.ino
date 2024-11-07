//This code will cause the BOEbot to go forward, bearing RIGHT, for as long as it is on.
//This uses pair one: Half is slightly FASTER than true 1/2 speed.

#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;
int FullClock = 1300; //write value for full speed clockwise rotation
int FullAnti = 1700; //write value for full speed anticlockwise rotation
int HalfClock = 1450; //write value for half speed clockwise rotation
int HalfAnti = 1550; //write value for half speed anticlockwise rotation

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);
}

void loop() {
//In order to bear right, the right wheel must turn clockwise at half speed
//and the left wheel must turn anticlockwise at full speed
RightWheel.writeMicroseconds(HalfClock);
LeftWheel.writeMicroseconds(FullAnti);
}

//This code will cause the BOEbot to go forward, bearing LEFT, for as long as it is on.
//This uses pair two: Half is slightly SLOWER than true 1/2 speed.

#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;
int FullClock = 1300; //write value for full speed clockwise rotation
int FullAnti = 1700; //write value for full speed anticlockwise rotation
int HalfClock = 1460; //write value for half speed clockwise rotation
int HalfAnti = 1540; //write value for half speed anticlockwise rotation

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);
}

void loop() {
//In order to bear left, the right wheel must turn clockwise at full speed
//and the left wheel must turn anticlockwise at half speed
RightWheel.writeMicroseconds(FullClock);
LeftWheel.writeMicroseconds(HalfAnti);
}

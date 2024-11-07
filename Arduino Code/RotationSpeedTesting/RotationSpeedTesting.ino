#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;
int HalfClock = 1460; //write value for half speed clockwise rotation Alt: 1450
int HalfAnti = 1540; //write value for half speed anticlockwise rotation Alt: 1550
int FullClock = 1300; //write value for full speed clockwise rotation
int FullAnti = 1700; //write value for full speed anticlockwise rotation
int Stop = 1500;

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);
}

void loop() {
delay(4000); //waits 4 seconds before motion begins
//Forward and bearing right: Right wheel clockwise 1/2x speed, left wheel anticlockwise 1x speed
RightWheel.writeMicroseconds(HalfClock);
LeftWheel.writeMicroseconds(FullAnti);
delay(5000); //for 5 seconds
RightWheel.writeMicroseconds(Stop);
LeftWheel.writeMicroseconds(Stop); //then stops
delay(3000); //waits 3 seconds between motions
//Forward bearing left: Right wheel clockwise 1x speed, left wheel anticlockwise 1/2x speed
RightWheel.writeMicroseconds(FullClock);
LeftWheel.writeMicroseconds(HalfAnti);
delay(5000); //for 5 seconds
RightWheel.writeMicroseconds(Stop);
LeftWheel.writeMicroseconds(Stop); //then stops
delay(4000); //waits 4 seconds after motion ends
}

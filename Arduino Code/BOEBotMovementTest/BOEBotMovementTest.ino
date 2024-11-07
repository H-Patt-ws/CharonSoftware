#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;

void setup() {
RightWheel.attach(12);
LeftWheel.attach(13);
}

void loop() {
RightWheel.writeMicroseconds(1500); //Signalling both wheels to stop...
LeftWheel.writeMicroseconds(1500);
delay(5000);                        // ...For 5 seconds

//Forward - Right wheel clockwise, left anticlockwise
RightWheel.writeMicroseconds(1300);
LeftWheel.writeMicroseconds(1700);
delay(1000); //Moves forward for 1 second
RightWheel.writeMicroseconds(1500);
LeftWheel.writeMicroseconds(1500); //stops

delay(1000); //delay of 1s between motions

//Backward - Right wheel anticlockwise, left clockwise
RightWheel.writeMicroseconds(1700);
LeftWheel.writeMicroseconds(1300);
delay(1000); //Moves backward for 1 second
RightWheel.writeMicroseconds(1500);
LeftWheel.writeMicroseconds(1500); //stops

delay(1000); //delay of 1s between motions

//Spin Right - Both wheels anticlockwise
RightWheel.writeMicroseconds(1700);
LeftWheel.writeMicroseconds(1700);
delay(2050); //delay of 2.05s, which results in a 360 degree turn right
RightWheel.writeMicroseconds(1500);
LeftWheel.writeMicroseconds(1500); //stops

delay(1000); //delay of 1s between motions

//Spin Left - Both wheels clockwise
RightWheel.writeMicroseconds(1300);
LeftWheel.writeMicroseconds(1300); //Both wheels turn anticlockwise, so robot turns clockwise
delay(2125); //delay of 2.125s, which results in a 360 degree turn left
RightWheel.writeMicroseconds(1500);
LeftWheel.writeMicroseconds(1500); //stops
}


//Code for Slave module//
#include <Servo.h>
Servo RightWheel;
Servo LeftWheel;

#define ledPin 8
#define slaveSwitchPin 7
int dataFromMaster = 0;
int Stop = 1500;
int LeftFullClock = 1395;
int LeftFullAnti = 1604;
int RightFullClock = 1375;
int RightFullAnti = 1618;

void Forward(){
  RightWheel.writeMicroseconds(RightFullClock);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Backward(){
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftFullClock);
}

void LeftTurn(){
  RightWheel.writeMicroseconds(RightFullClock);  
  LeftWheel.writeMicroseconds(LeftFullClock);
}

void RightTurn(){ 
  RightWheel.writeMicroseconds(RightFullAnti);
  LeftWheel.writeMicroseconds(LeftFullAnti);
}

void Still(){
  RightWheel.writeMicroseconds(Stop);
  LeftWheel.writeMicroseconds(Stop);
}

void setup() {
  RightWheel.attach(12);
  LeftWheel.attach(13);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(slaveSwitchPin, INPUT);
  digitalWrite(slaveSwitchPin,LOW);
  Serial.begin(38400); // Default baud rate of the Bluetooth module
}


void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromMaster = Serial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
   Serial.println(dataFromMaster);
 }
 // Controlling the led
 if (dataFromMaster == '2') {
  Backward();
  Serial.println("low ");
 }
 else if (dataFromMaster == '1') {
  Forward();
  Serial.println("high ");
 }
 else if (dataFromMaster == '0') {
  Still();
  Serial.println("low ");
 }
 
 // Reading the masterSwitchValue
 //int slaveSwitchValue = digitalRead(slaveSwitchPin);
 //if (slaveSwitchValue == HIGH) {
 //  Serial.write('1'); // Sends '1' to the master to turn on BUZZER
 //}
 //else {
 //  Serial.write('0');
 //}  

 delay(10);
}

//Code for Slave module//
#include <Servo.h>
#include <CharonMovement.h>
Servo RightWheel;
Servo LeftWheel;
Motion Move = Motion(RightWheel, LeftWheel);

#define ledPin 8
#define slaveSwitchPin 7
int dataFromMaster = 0;

void setup() {
  Move.Attach(12, 13);
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

switch (dataFromMaster){
  case (0):{
    Move.StayStill();
    Serial.println("Stop!");
  }
  break;
  case (1):{
    Move.Forward();
    Serial.println("Forth!");
  }
  break;
  case (3):{
    Move.RightTurn();
    Serial.println("Turn right!");
  }
  break;
  case (5):{
    Move.Backward();
    Serial.println("Back!");
  }
  break;
  case (7):{
    Move.LeftTurn();
    Serial.println("Turn left!");
  }
  break;
  default:{
    Move.StayStill();
    Serial.println("No Signal!");
  }
}
 
 // Reading the slaveSwitchValue
 //int slaveSwitchValue = digitalRead(slaveSwitchPin);
 //if (slaveSwitchValue == HIGH) {
 //  Serial.write('1'); // Sends '1' to the master to turn on BUZZER
 //}
 //else {
 //  Serial.write('0');
 //}  

 delay(1000);
}

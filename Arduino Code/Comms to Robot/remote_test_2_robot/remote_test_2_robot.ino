//Code for Slave module//


#include <Servo.h>
#include <CharonMovement.h>
#include <SoftwareSerial.h>

//SoftwareSerial mySerial =  SoftwareSerial(11, 12);
SoftwareSerial BTSerial(11, 12);
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
  BTSerial.begin(38400);
}


void loop() {
 if(BTSerial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromMaster = 9;
   dataFromMaster = Serial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
   BTSerial.println(dataFromMaster);
 }

switch (dataFromMaster){
  case ('0'):{
    Move.StayStill();
    BTSerial.println("Stop!");
  }
  break;
  case ('1'):{
    Move.Forward();
    BTSerial.println("Forth!");
  }
  break;
  case ('3'):{
    Move.RightTurn();
    BTSerial.println("Turn right!");
  }
  break;
  case ('5'):{
    Move.Backward();
    BTSerial.println("Back!");
  }
  break;
  case ('7'):{
    Move.LeftTurn();
    BTSerial.println("Turn left!");
  }
  break;
  default:{
    Move.StayStill();
    BTSerial.println("No Signal!");
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

 delay(10);
}

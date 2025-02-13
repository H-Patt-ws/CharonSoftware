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
  Serial.begin(9600); // Default baud rate of the Bluetooth module
  BTSerial.begin(38400);
}


void loop() {
 if(BTSerial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromMaster = 9;
   dataFromMaster = BTSerial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
   Serial.println(dataFromMaster);
 }

switch (dataFromMaster){
  case ('0'):{
    Move.StayStill();
    Serial.println("Stop!");
  }
  break;
  case ('1'):{
    Move.Forward();
    Serial.println("Forth!");
  }
  break;
  case ('2'):{
    Move.ForwardRight();
    Serial.println("Forward, bear right!");
  }
  break;
  case ('3'):{
    Move.RightTurn();
    Serial.println("Turn right!");
  }
  break;
  case ('4'):{
    Move.BackwardRight();
    Serial.println("Backward, bear right!");
  }
  break;
  case ('5'):{
    Move.Backward();
    Serial.println("Back!");
  }
  break;
  case ('6'):{
    Move.BackwardLeft();
    Serial.println("Backward, bear left!");
  }
  break;
  case ('7'):{
    Move.LeftTurn();
    Serial.println("Turn left!");
  }
  break;
  case ('8'):{
    Move.ForwardLeft();
    Serial.println("Forward, bear left!");
  }
  break;
  default:{
    Move.StayStill();
    Serial.println("No Signal!");
  }
}
 delay(10);
}

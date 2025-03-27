//Code for Slave module//


#include <Servo.h>
#include <CharonMovement.h>
#include <SoftwareSerial.h>

//SoftwareSerial mySerial =  SoftwareSerial(11, 12);
SoftwareSerial BTSerial(11, 12);
Servo RightWheel;
Servo LeftWheel;
Motion Move = Motion(RightWheel, LeftWheel);

#define buzzer 8

#define slaveSwitchPin 7
int dataFromMaster = 0;
int movMode;
int orderSwitch = 0; //order from the switch this cycle. "Carry" is denoted as 0, "Pick up" as 1 and "Drop" as 2
int lastSwitch = 0; //order from the switch last cycle

void setup() {
  Move.Attach(12, 13);
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer, LOW);
  pinMode(slaveSwitchPin, INPUT);
  digitalWrite(slaveSwitchPin,LOW);
  Serial.begin(9600); // Default baud rate of the Bluetooth module
  BTSerial.begin(38400);
}

void loop() {
 if(BTSerial.available() > 0){ // Checks whether data is coming from the serial port
   dataFromMaster = 9;
   dataFromMaster = BTSerial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
   Serial.println(dataFromMaster);
 }

 //Serial.println(dataFromMaster);
 if (dataFromMaster>=0 && dataFromMaster<=8){
  //Serial.println("toggle on");
  orderSwitch = 0; //"Carry" order
  movMode = dataFromMaster;
  Serial.println(movMode);
  movement(movMode);
 }
 else if (dataFromMaster>= 16 && dataFromMaster<=24) {
  Serial.println("toggle half");
  orderSwitch = 2; //"Drop" order
  if (lastSwitch != orderSwitch){
    tone(buzzer, 262, 500);
  }
  movMode = dataFromMaster - 16;
  Serial.println(movMode);
  movement(movMode);
 }
 else if (dataFromMaster>= 32 && dataFromMaster<=40){
  Serial.println("toggle half");
  orderSwitch = 1; //"Pick up" order
  if (lastSwitch != orderSwitch){
    tone(buzzer, 392, 500);
  }
  movMode = dataFromMaster - 32;
  Serial.println(movMode);
  movement(movMode);
 }
 else if (dataFromMaster==9){
  Serial.println("no signal!");
 }
 else {
  //Serial.println("an error has occured");
 }
lastSwitch = orderSwitch;
}

void movement(int movMode){
  switch (movMode){
    case (0):{
      Move.StayStill();
      //Serial.println("Stop!");
      //Serial.println("0");
    }
    break;
    case (1):{
      Move.Forward();
      //Serial.println("Forth!");
      //Serial.println("1");
    }
    break;
    case (2):{
      Move.ForwardRight();
      //Serial.println("Forward, bear right!");
      //Serial.println("2");
    }
    break;
    case (3):{
      Move.RightTurn();
      //Serial.println("Turn right!");
      //Serial.println("3");
    }
    break;
    case (4):{
      Move.BackwardRight();
      //Serial.println("Backward, bear right!");
      //Serial.println("4");
    }
    break;
    case (5):{
      Move.Backward();
      //Serial.println("Back!");
    }
    break;
    case (6):{
      Move.BackwardLeft();
      //Serial.println("Backward, bear left!");
      //Serial.println("6");
    }
    break;
    case (7):{
      Move.LeftTurn();
      //Serial.println("Turn left!");
      //Serial.println("7");
    }
    break;
    case (8):{
      Move.ForwardLeft();
      //Serial.println("Forward, bear left!");
      //Serial.println("8");
    }
    break;
    default:{
      Move.StayStill();
      //Serial.println("No Signal!");
      //Serial.println("9");
    }
  }
  delay(10);
}

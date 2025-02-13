//Joystick Base Code
//14.11.2024
//Nikitha Prabhakar

/*
This code is a base for the analogue joystick
It defines 9 movement regions and if an input doesn't fall in a region, it defaults to "stay still"
I've tried two sets of ranges with varying border width. The border width appears to affect the "Stay Still" radius and so it's still proned to slippage.
Hopefully we can correct this in the physical controller design
**Please ensure the VRx,VRy pins are connected correctly**
The switch case is at the end of the code!
*/

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SWITCH_PIN_1  8  // Button pin
#define SWITCH_PIN_2  9  // Button pin
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 12);

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis


void setup() {
  pinMode(SWITCH_PIN_1, INPUT);
  pinMode(SWITCH_PIN_2, INPUT);
  Serial.begin(9600);
  BTSerial.begin(38400);
}
int Position(int coordinate) {
  //two area sizes tested to see the effect on the joystick control.
  //smaller border = smaller "stay still" radius for the joystick
  
    int ranges[3][2]= {
    {0,293}, 
    {365,654}, 
    {730,1023}
  };
  //larger border = larger "stay still" radius for the joystick
  /*int ranges[3][2]= {
    {0,241}, 
    {391,632}, 
    {782,1023}
  };*/

  //initialising the values that determine if the value falls into a defined region and which region the value falls it into
  int value_set = 0;
  int pos = 0;

  //loops through the 3 ranges defined in the array "ranges"
  for(int i=0; i<3; i++){
    //sets the lower and upper limit for the region from the array
    int lower = ranges[i][0];
    int higher = ranges[i][1];
    //if the value falls within the tested range, the position is set to the iteration number and the "value has been set"
    if(lower<=coordinate && coordinate<=higher){
      pos = i;
      value_set = 1;
    };
  };
  //if the value doesn't fit in a region it defaults to "stay still" and for tracking the variables, it sets "value_set" to 1
  if(value_set == 0){
    value_set = 1;
    pos = 1;
  };
  return pos;
}

void loop() {
  //Gets the x and y coordinates NOTE: Make sure the pins are wired correctly, I ran into issues with this.
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);

  //This is the joystick region map based on the controller testing naming convention
  int region_map[3][3]= {
    {8,1,2}, 
    {7,0,3}, 
    {6,5,4}
  };
  /*
  //Used for testing and retrieving the x,y coordinates
  BTSerial.print("x = ");
  BTSerial.print(xValue);
  BTSerial.print(", y = ");
  BTSerial.println(yValue);
  delay(200);
  */

  //Uses the Position function to get the horizontal and vertical joystick map coordinates. The horizontal maps left to right. The vertical maps top to bottom.
  int pos_hz = Position(xValue);
  int pos_vt = Position(yValue);

  /*
  //Used for testing and retrieving region map coordinates
  BTSerial.print("hz = ");
  BTSerial.print(pos_hz);
  BTSerial.print(", vt = ");
  BTSerial.println(pos_vt);
  delay(200);
  */
  
  //Selects the correct case number from the region map
  int case_number = region_map[pos_vt][pos_hz];
  /*Serial.println(case_number);
  delay(200);
  */

  int message = 0;// to send data to the BT serial 

  //Switch case that uses the controller test naming convention to output the respective movement.
  //Please insert your functions into the cases.

  switch(case_number) {
  case 0:
    Serial.println("Stay Still");
    message = 0;
    Serial.println(message);
    break;
  case 1:
    Serial.println("Forward");
    message = 1;
    Serial.println(message);
    break;
  case 2:
    Serial.println("Forward Right");
    message = 2;
    Serial.println(message);
    break;
  case 3:
    Serial.println("Right");
    message = 3;
    Serial.println(message);
    break;
  case 4:
    Serial.println("Backward Right");
    message = 4;
    Serial.println(message);
    break;
  case 5:
    Serial.println("Backward");
    message = 5;
    Serial.println(message);
    break;
  case 6:
    Serial.println("Backward Left");
    message = 6;
    Serial.println(message);
    break;
  case 7:
    Serial.println("Left");
    message = 7;
    Serial.println(message);
    break;
  case 8:
    Serial.println("Forward Left");
    message = 8;
    Serial.println(message);
    break;
  }
  
  int SwitchValue1 = digitalRead(SWITCH_PIN_1);
  int SwitchValue2 = digitalRead(SWITCH_PIN_2);

  if ((SwitchValue1 == HIGH) && (SwitchValue2 == LOW)) {
    message += 32;
    Serial.println(message);
    Serial.println("left");
  }
  if ((SwitchValue1 == LOW) && (SwitchValue2 == HIGH)) {
    message += 16;
    Serial.println(message);
    Serial.println("right");
  } 
  else if ((SwitchValue1 == LOW) && (SwitchValue2 == LOW)){
    message = message ;
    Serial.println(message);
    Serial.println("middle");
  }
  else if ((SwitchValue1 == HIGH) && (SwitchValue2 == HIGH)){
    Serial.println("WRONG");
  }

  //Serial.println(message);
  BTSerial.write(message);

  //delay gives it a chance to breathe!
  delay(200);
  
}
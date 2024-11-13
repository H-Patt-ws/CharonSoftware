#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

#define LEFT_THRESHOLD  293
#define RIGHT_THRESHOLD 730
#define UP_THRESHOLD    293
#define DOWN_THRESHOLD  730

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis

void setup() {
  Serial.begin(9600) ;
}

void loop() {
  //Serial.print("a");

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  Serial.println(xValue);
  Serial.println(yValue);

  // check left/right commands
  switch (xValues) {
    case (1):{
      switch(){
        case 1:{
          printf("Monday");
          break;
        }
        case 2:{
          printf("Tuesday");
          break;
        }
        case 3:{
          printf("Wednesday");
          break;
        }
      }
      break;
    }
  
  case 2:{
    switch(){
      case 1:{
        printf("Monday");
        break;
      }
      case 2:{
        printf("Tuesday");
        break;
      }
      case 3:{
        printf("Wednesday");
        break;
      }
    }
    break;
  }
     
  case 3:{
    switch(){
      case 1:{
        printf("Monday");
        break;
      }
      case 2:{
        printf("Tuesday");
        break;
      }
      case 3:{
        printf("Wednesday");
        break;
      }
    }
    break;
  }
  

  if ((xValue < LEFT_THRESHOLD)){
    if (yValue)
    //Move.LeftTurn();
    Serial.println("Turn left!");
  }

  else if ((xValue > RIGHT_THRESHOLD)){
    //Move.RightTurn();
    Serial.println("Turn right!");
  }

  // check up/down commands
  //if (yValue < UP_THRESHOLD)
  //  command = command | COMMAND_UP;
  //else if (yValue > DOWN_THRESHOLD)
  //  command = command | COMMAND_DOWN;

  // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS

  /*// print command to serial and process command
  if (command & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    // TODO: add your task here
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    // TODO: add your task here
  }

  if (command & COMMAND_UP) {
    Serial.println("COMMAND UP");
    // TODO: add your task here
  }

  if (command & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    // TODO: add your task here
  }
  */
}


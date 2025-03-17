#include <Servo.h>

#define SERVO_PIN 9

// Define angles for each step
#define PICKUP 0    // Angle for picking up the token (clockwise)
#define CARRY 90    // Neutral angle for carrying the token
#define DROP 180    // Angle for dropping the token (anticlockwise)

Servo myServo;

void setup() {
 
  myServo.attach(SERVO_PIN);

  Serial.begin(9600);
  Serial.println("Servo Token Pickup Mechanism Initialized!");
  
  myServo.write(CARRY);

  delay(1000); 
}

void loop() {

  pickupToken();
  delay(1000); 

  carryToken();
  delay(1000); 


  dropToken();
  delay(1000); 
}

// Function to pick up the token 
void pickupToken() {

  Serial.println("Picking up token...");

  myServo.write(PICKUP); 

  delay(500); 
}

// Function to carry the token
void carryToken() {
  
  Serial.println("Carrying token...");

  myServo.write(CARRY); 
  
  delay(500); 
}

// Function to drop the token (anticlockwise rotation)
void dropToken() {
  Serial.println("Dropping token...");
  myServo.write(DROP); 
  delay(500); 
}

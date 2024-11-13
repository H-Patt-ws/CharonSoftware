//Code for master module//

#define greenLedPin 8
#define forwardSwitchPin 7
#define backwardSwitchPin 4
int dataFromSlave = 0;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  pinMode(forwardSwitchPin, INPUT);
  pinMode(backwardSwitchPin, INPUT);
  digitalWrite(forwardSwitchPin,LOW);
  digitalWrite(backwardSwitchPin,LOW);
  Serial.begin(38400); // Default baud rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 }

 // Reading the switch values
 int forwardSwitchValue = digitalRead(forwardSwitchPin);
 int backwardSwitchValue = digitalRead(backwardSwitchPin);

 if (forwardSwitchValue == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on LED
 }
 else if (backwardSwitchValue == HIGH) {
   Serial.write('3'); // Sends '1' to the master to turn on LED
 }
 else {
   Serial.write('0');
 }  

 delay(10);
}

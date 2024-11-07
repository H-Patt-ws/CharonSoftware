//Code for master module//

#define greenLedPin 8
#define masterSwitchPin 7
int dataFromSlave = 0;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  pinMode(masterSwitchPin, INPUT);
  digitalWrite(masterSwitchPin,LOW);
  Serial.begin(9600); // Default baud rate of the Bluetooth module
}
void loop() {
 /*
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   ///dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 }
  Controlling the Buzzer
 if (dataFromSlave == '1') {
  digitalWrite(greenLedPin, HIGH); // led ON
 }
 else if (dataFromSlave == '0') {
  digitalWrite(greenLedPin, LOW); // led OFF
 }
 */
 // Reading the masterSwitchValue
 int masterSwitchValue = digitalRead(masterSwitchPin);
 if (masterSwitchValue == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on BUZZER
 }
 else if (masterSwitchValue == LOW){
   Serial.write('0');
 }
  //int pin1 = digitalRead(1);
  //Serial.println(pin1);  
 delay(10);
}

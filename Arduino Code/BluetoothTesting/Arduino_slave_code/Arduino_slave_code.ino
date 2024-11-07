//Code for Slave module//

#define ledPin 8
#define slaveSwitchPin 7
int dataFromMaster = 0;

void setup() {
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
 if (dataFromMaster == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
 }
 else if (dataFromMaster == '0') {
  digitalWrite(ledPin, LOW); // LED    OFF
 }
 
 // Reading the masterSwitchValue
 int slaveSwitchValue = digitalRead(slaveSwitchPin);
 if (slaveSwitchValue == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on BUZZER
 }
 else {
   Serial.write('0');
 }  

 delay(10);
}

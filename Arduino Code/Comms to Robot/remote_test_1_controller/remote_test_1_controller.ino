//Code for master module//

#define ForwardPin 7
#define BackwardPin 4
#define LeftPin 11
#define RightPin 13
int dataFromSlave = 0;

void setup() {
  pinMode(ForwardPin, INPUT);
  pinMode(BackwardPin, INPUT);
  pinMode(LeftPin, INPUT);
  pinMode(RightPin, INPUT);
  digitalWrite(ForwardPin,LOW);
  digitalWrite(BackwardPin,LOW);
  digitalWrite(LeftPin, LOW);
  digitalWrite(RightPin, LOW);
  Serial.begin(38400); // Default baud rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 }
 // Controlling the GreenLED PIN
 //if (dataFromSlave == '0') {
 // digitalWrite(greenLedPin, LOW); // led ON
 //}
 //else if (dataFromSlave == '1') {
 // digitalWrite(greenLedPin, HIGH); // led OFF
 //}
 
 
 int ForwardValue = digitalRead(ForwardPin);
 int BackwardValue = digitalRead(BackwardPin);
 int LeftValue = digitalRead(LeftPin);
 int RightValue = digitalRead(RightPin);


 if (ForwardValue == HIGH) {
   Serial.write('1'); 
 }
 else if (BackwardValue == HIGH) {
   Serial.write('5'); 
 }
 else if (LeftValue == HIGH){
   Serial.write('7');
 }
 else if (RightValue == HIGH){
   Serial.write('3');
 }
 else {
   Serial.write('0');
 }  

 delay(10);
}

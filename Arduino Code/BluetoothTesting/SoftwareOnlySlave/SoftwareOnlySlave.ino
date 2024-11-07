int dataFromMaster = 2;

void setup() {
Serial.begin(38400);

}

void loop() {
if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  dataFromMaster = Serial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
 }
if (dataFromMaster == '0'){
  printf("Negative!");
}

else if (dataFromMaster == '1'){
  printf("Positive!");
}

else{
  printf("No signal!");
}
delay(10);
}

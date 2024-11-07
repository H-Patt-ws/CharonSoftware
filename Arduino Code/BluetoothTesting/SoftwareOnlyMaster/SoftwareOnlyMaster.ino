
int dataFromSlave = 0;
int dataToSend;

void setup() {
  Serial.begin(38400);
}

void loop() {

scanf("%d", &dataToSend);
Serial.write(dataToSend);

/*
if (dataToSend == 1){
  Serial.write('1');
}
else if (dataToSend == 0){
  Serial.write('0');
}
*/

/*
if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 }

if (dataFromSlave == 1){
  printf("One!");
}
else if (dataFromSlave == 0){
  printf("Zero!");
}
else {
  printf("No Signal!");
}
*/

delay(2000);
}

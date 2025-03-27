int signal = 0;
int lastSignal = 0;

//In this, the IR sensor sends a new message to the serial when its state changes.
//Demonstrates IR sensor's function 
//Demonstrates the ability to store IR reading and compare it to other values

void setup()  {
    Serial.begin(9600);
    pinMode(13,INPUT);
}
void loop()  {
    while(1)  {
        delay(500);
        if(digitalRead(13)==LOW)  {
            signal = 1;
        }
        else  {
            signal = 0;
        }
        if (signal == 1 && lastSignal == 0){
          Serial.println("Token");
        }
        else if (signal == 0 && lastSignal == 1){
          Serial.println("Nothing");
        }
      lastSignal = signal;
    }
}
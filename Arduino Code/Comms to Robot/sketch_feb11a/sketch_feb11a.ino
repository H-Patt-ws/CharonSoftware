#define SWITCH_PIN_1  2  // left pin
#define SWITCH_PIN_2  3  // right pin

void setup() {
  // put your setup code here, to run once:
  pinMode(SWITCH_PIN_1, INPUT);
  digitalWrite(SWITCH_PIN_1, LOW);
  pinMode(SWITCH_PIN_2, INPUT);
  digitalWrite(SWITCH_PIN_2, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SwitchValue1 = digitalRead(SWITCH_PIN_1);
  int SwitchValue2 = digitalRead(SWITCH_PIN_2);

  //Serial.println(SwitchValue1);
  //Serial.println(SwitchValue2);

  if ((SwitchValue1 == HIGH) && (SwitchValue2 == LOW)){
    Serial.println("left");
  }
  if ((SwitchValue2 == HIGH) && (SwitchValue1 == LOW)) {
    Serial.println("right");
  } 
  else if ((SwitchValue1 == HIGH) && (SwitchValue2 == HIGH)){
    Serial.println("WRONG");
  } 
  else if ((SwitchValue1 == LOW) && (SwitchValue2 == LOW)){
    Serial.println("middle");
  }
  delay(200);

}

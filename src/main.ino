int sortida = 8;

void setup() {}


void loop() {
  digitalWrite(sortida, HIGH);
  delay(150);
  digitalWrite(sortida, LOW);
  delay(350);
  digitalWrite(sortida, HIGH);
  delay(550);
  digitalWrite(sortida, LOW);/*
  delay(350);
  digitalWrite(sortida, HIGH);
  delay(150);
  digitalWrite(sortida, LOW);*/
}

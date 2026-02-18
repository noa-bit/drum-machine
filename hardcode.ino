int potentiometer = A0;

void setup() {
  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
}

void loop() {
  int value = (analogRead(potentiometer)/4) + 80;  // integer division

  Serial.print("1 ");
  Serial.print(value);
  Serial.print(" 10 16 1 16 4 0 1 0.5 1 15000 0 1 16 4 2 1 0.5 1 15000 0 0 16 16 0 1 0.5 1 15000 0 8 7 5 1 0.5 0.5 1 15000 0.4 25 12 9 0 1 0.5 3 15000 0 0 8 3 2 1 0.5 2 8000 3.1 0");
  Serial.println();

  delay(100);
}

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  analogWrite(3, 10);
  analogWrite(5, 10);
  analogWrite(6, 10);
  analogWrite(9, 10);
  analogWrite(10, 10);
  analogWrite(11, 10);
  delay(1000);
  
  analogWrite(3, 50);
  analogWrite(5, 50);
  analogWrite(6, 50);
  analogWrite(9, 50);
  analogWrite(10, 50);
  analogWrite(11, 50);
  delay(1000);
  
  analogWrite(3, 100);
  analogWrite(5, 100);
  analogWrite(6, 100);
  analogWrite(9, 100);
  analogWrite(10, 100);
  analogWrite(11, 100);
  delay(1000);
  
  analogWrite(3, 150);
  analogWrite(5, 150);
  analogWrite(6, 150);
  analogWrite(9, 150);
  analogWrite(10, 150);
  analogWrite(11, 150);
  delay(1000);

  analogWrite(3, 200);
  analogWrite(5, 200);
  analogWrite(6, 200);
  analogWrite(9, 200);
  analogWrite(10, 200);
  analogWrite(11, 200);
  delay(1000);
  
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 255);
  analogWrite(9, 255);
  analogWrite(10, 255);
  analogWrite(11, 255);
  delay(1000);
}

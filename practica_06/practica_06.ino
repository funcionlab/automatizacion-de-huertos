int luz;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
luz = analogRead(0);
  
luz = map(luz, 0, 1023, 0, 100);
  
  if (luz <= 20) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
  }
  
  if ((luz > 20) && (luz <= 30)) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }
  
  if ((luz > 40) && (luz <= 60)) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }
  
  if ((luz > 60) && (luz <= 80)) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }
  
  if ((luz > 80) && (luz <= 90)) {
    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }
  
  if ((luz > 90) && (luz <= 100)) {
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }
  
  Serial.print("Porcentaje de Luz = ");
  Serial.print(luz);
  Serial.println(" %");
  
  delay(100);
}

int luz;

void setup() {
  Serial.begin(9600);
}

void loop() {
  luz = analogRead(0);
  
  luz = map(luz, 0, 1023, 0, 2000);
  
  Serial.print("Luz = ");
  Serial.print(luz);
  Serial.println(" Lumenes");
  
  delay(500);
}

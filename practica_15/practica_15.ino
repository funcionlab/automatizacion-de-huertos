#define pin_sensor 2

int nivel_de_agua;

void setup() {
  Serial.begin(9600);
}

void loop() {
  nivel_de_agua = analogRead(pin_sensor);

  Serial.print("Nivel de Agua ");
  Serial.println(nivel_de_agua);
  
  if (nivel_de_agua > 400) {
    Serial.println("Tanque lleno");
  }
  
  delay(800);
}

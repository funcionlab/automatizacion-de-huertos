#define sensor_de_nivel 0
#define bomba 2

int nivel_de_agua = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(bomba, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(13, LOW);
}

void loop() {
  nivel_de_agua = analogRead(sensor_de_nivel);
  
  Serial.print("Nivel de Agua ");
  Serial.println(nivel_de_agua);
  
  if (nivel_de_agua > 400) {
    digitalWrite(bomba, LOW);
    
    Serial.println("Tanque lleno");
    
    digitalWrite(13, LOW);
  } else {
    digitalWrite(bomba, HIGH);
    
    Serial.println("Bomba Activada");
    
    digitalWrite(13,HIGH);
  }
  
  delay(500);
}

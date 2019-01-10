int humedad_del_suelo;

void setup() {
  pinMode(2,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  humedad_del_suelo = analogRead(0);
  
  //Convertimos el valor analogo 0-1023 a porcentaje 100-0
  humedad_del_suelo = map(humedad_del_suelo, 0, 1023, 100, 0);
  
  Serial.print("Porcentaje de Humedad de la Tierra ");
  Serial.print(humedad_del_suelo);
  Serial.println(" %");
  
  if (humedad_del_suelo <= 40) {
    Serial.println("Tierra Muy Seca, RIEGO ACTIVADO");
    
    digitalWrite(2,1);
  }
  
  if ((humedad_del_suelo > 40) and (humedad_del_suelo <= 65)) {
    digitalWrite(2,0);
    
    Serial.println("Tierra con buena humedad");
  }
  
  if (humedad_del_suelo > 65) {
    digitalWrite(2,0);
    
    Serial.println("Demasiada Agua, REQUIERE DRENAR AGUA");
  }
  
  delay(800);
}

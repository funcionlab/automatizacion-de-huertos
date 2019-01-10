#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h> //Se llama a la librería del sensor

DHT sensor_DHT(9, DHT11); // sensor conectado en pin9 y el tipo es DHT11

OneWire pin(8); //conectado en pin 8

DallasTemperature sensor_temperatura(&pin);

float temperatura = 0;

void setup() {
  Serial.begin(9600);
  
  sensor_DHT.begin();
  sensor_temperatura.begin();
  
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int luz = analogRead(0);
  int humedad = sensor_DHT.readHumidity();
  int temperatura_ambiente = sensor_DHT.readTemperature();
  
  luz = map(luz, 0, 1023, 0, 100);
  
  sensor_temperatura.requestTemperatures();
  
  temperatura = sensor_temperatura.getTempCByIndex(0);
  
  Serial.print("Cantidad de Luz= ");
  Serial.print(luz);
  Serial.print(" %, ");
  Serial.print("Temperatura de la tierra= ");
  Serial.print(temperatura);
  Serial.print(", Humedad= ");
  Serial.print(humedad);
  Serial.print(", Temperatura ambiente= ");
  Serial.println(temperatura_ambiente);
  
  if (temperatura_ambiente >= 30) {
    digitalWrite(2, HIGH);
    digitalWrite(13, HIGH);
    
    Serial.println("VENTILADOR ACTIVADO");
  } else {
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
    
    Serial.println("VENTILADOR DESACTIVADO");
  }
  
  delay(500);
}

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire pin(5); //conectado en pin 5

DallasTemperature sensor(&pin);

float temperatura = 0;

void setup() {
  Serial.begin(9600);
  
  sensor.begin();
  
  pinMode(2, OUTPUT);
}

void loop() {
  sensor.requestTemperatures();
  
  temperatura = sensor.getTempCByIndex(0);
  
  if (temperatura > 30) {
    digitalWrite(2, HIGH);
    
    Serial.println("BOMBA DE AGUA ACTIVADA");
  } else {
    digitalWrite(2, LOW);
    
    Serial.println("BOMBA DE AGUA DESACTIVADA");
  }
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" Grados Centigrados");
}

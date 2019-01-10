#include <OneWire.h>
#include <DallasTemperature.h>

OneWire pin(5); //conectado en pin 5
DallasTemperature sensor(&pin);
float temperatura = 0;

void setup() {
  Serial.begin(9600);
  
  sensor.begin();
}

void loop() {
  sensor.requestTemperatures();
  
  temperatura = sensor.getTempCByIndex(0);
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" Grados Centigrados");
}

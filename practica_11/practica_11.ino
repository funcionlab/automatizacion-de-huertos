#include <OneWire.h>
#include <DallasTemperature.h>

OneWire pin5(5); //conectado en pin 5
DallasTemperature sensor1(&pin5);

OneWire pin4(4); //conectado en pin 4
DallasTemperature sensor2(&pin4);

float Temperatura1 = 0;
float Temperatura2 = 0;

void setup() {
  Serial.begin(9600);
  
  sensor1.begin();
  sensor2.begin();
}

void loop() {
  sensor1.requestTemperatures();
  
  Temperatura1 = sensor1.getTempCByIndex(0);

  sensor2.requestTemperatures();

  Temperatura2 = sensor2.getTempCByIndex(0);

  Serial.print("Temperatura del Sensor 1: ");
  Serial.print(Temperatura1);
  Serial.println(" Grados Centigrados");
  Serial.print("Temperatura del Sensor 2: ");
  Serial.print(Temperatura2);
  Serial.println(" Grados Centigrados");
}

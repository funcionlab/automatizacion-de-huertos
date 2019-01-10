#include <DHT.h> //Se llama a la librería del sensor

DHT sensor1(8, DHT11); // sensor1 conectado en pin8 y el tipo es DHT11
DHT sensor2(9, DHT11); // sensor2 conectado en pin9 y el tipo es DHT11

void setup() {
  Serial.begin(9600); // se inicializa el puerto serie

  sensor1.begin();
  sensor2.begin();
}

void loop() {
  int h1 = sensor1.readHumidity();
  int t1 = sensor1.readTemperature();
  int h2 = sensor2.readHumidity();
  int t2 = sensor2.readTemperature();

  //Se imprimen los valores en el monitor serial
  Serial.print("sensor 1: ");
  Serial.print("Temperatura= ");
  Serial.print(t1);
  Serial.print(" Grados, ");
  Serial.print("Humedad= ");
  Serial.print(h1);
  Serial.println(" %");
  Serial.print("sensor 2: ");
  Serial.print("Temperatura= ");
  Serial.print(t2);
  Serial.print(" Grados, ");
  Serial.print("Humedad= ");
  Serial.print(h2);
  Serial.println(" %");
  
  delay(1000);
}

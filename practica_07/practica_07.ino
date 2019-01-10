#include <DHT.h> //Se llama a la librería del sensor

DHT dht(8, DHT11); // sensor conectado en pin8 y el tipo es DHT11

void setup() {
  Serial.begin(9600); // se inicializa el puerto serie
  
  dht.begin(); // Se inicializa el sensor DHT11
}

void loop() {

  //el método readHumidity lee la humedad y se asigna a h
  int h = dht.readHumidity(); 
  
  //el método readTemperature lee la temperatura y se asigna a t
  int t = dht.readTemperature(); 
  
  //Se imprimen los valores en el monitor serial
  Serial.print("Temperatura ");
  Serial.print(t);
  Serial.println(" Grados Centigrados");
  Serial.print("Porcentaje de Humedad ");
  Serial.print(h);
  Serial.println(" %");
  
  delay(1000);
}

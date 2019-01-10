#include <DHT.h> //Se llama a la librería del sensor
#define sensor_analogico analogRead(0);

DHT sensor_digital(8, DHT11); // sensor conectado en pin8 y el tipo es DHT11

int luz, humedad, temperatura;

void setup() {
  Serial.begin(9600); // se inicializa el puerto serie

  sensor_digital.begin(); // Se inicializa el sensor DHT11
}

void loop() {
  //el método readHumidity lee la humedad
  humedad = sensor_digital.readHumidity();
  
  //el método readTemperature lee la temperatura
  temperatura = sensor_digital.readTemperature(); 
  
  luz = sensor_analogico;
  
  luz = map(luz, 0, 1023, 0, 100);
  
  //Se imprimen los valores en el monitor serial
  Serial.print("Porcentaje de Luz = ");
  Serial.print(luz);
  Serial.println(" %");
  Serial.print("Temperatura ");
  Serial.print(temperatura);
  Serial.println(" Grados Centigrados");
  Serial.print("Porcentaje de Humedad ");
  Serial.print(humedad);
  Serial.println(" %");
  
  delay(1000);
}

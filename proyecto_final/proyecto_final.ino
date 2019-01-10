#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

#define bomba1 2
#define bomba2 3
#define Sensor_de_nivel 0
  
DHT sensor_DHT(4, DHT11);
OneWire pin(11); //conectado en pin 11
DallasTemperature sensor_temperatura(&pin);

float Temperatura = 0;
int humedad_del_suelo;
int nivel_de_agua = 0;

void setup() {
  pinMode(bomba1, OUTPUT);
  pinMode(bomba2, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(bomba1, LOW);
  digitalWrite(bomba2, LOW);
  
  sensor_DHT.begin();
  sensor_temperatura.begin();
}

void loop() {
  Llenado_del_Tanque();
  
  Luz();
  
  Humedad_y_Temperatura();
  
  Riego();
  
  Temperatura_de_la_tierra();
  
  delay(500);
}

void Riego() {
  humedad_del_suelo = analogRead(1);
  
  //Convertimos el valor analogo 0-1023 a porcentaje 100-0
  humedad_del_suelo = map(humedad_del_suelo, 0, 1023, 100, 0);
  
  Serial.print("Porcentaje de Humedad de la Tierra ");
  Serial.print(humedad_del_suelo);
  Serial.println(" %");
  
  if (humedad_del_suelo <= 40) {
    Serial.println("Tierra Muy Seca, RIEGO ACTIVADO");
    
    digitalWrite(bomba1, 1);
  }
  
  if ((humedad_del_suelo > 40) and (humedad_del_suelo <= 65)) {
    digitalWrite(bomba1, 0);
    
    Serial.println("Tierra con buena humedad");
  }
  
  if (humedad_del_suelo > 65) {
    digitalWrite(bomba1, 0);
    Serial.println("Demasiada Agua, REQUIERE DRENAR AGUA");
  }
}

void Luz() {
  int luz = analogRead(2);

  luz = map(luz, 0, 1023, 0, 100);

  Serial.print("Porcentaje de Luz= ");
  Serial.print(luz);
  Serial.println(" %");
}

void Humedad_y_Temperatura() {
  int humedad = sensor_DHT.readHumidity();
  int temperatura_ambiente = sensor_DHT.readTemperature();
  
  Serial.print("Humedad = ");
  Serial.print(humedad);
  Serial.print(" ,Temperatura ambiente = ");
  Serial.println(temperatura_ambiente);
}

void Temperatura_de_la_tierra() {
  sensor_temperatura.requestTemperatures();
  
  temperatura = sensor_temperatura.getTempCByIndex(0);
  
  Serial.print("Temperatura de la tierra= ");
  Serial.println(temperatura);
}

void Llenado_del_Tanque() {
  nivel_de_agua = analogRead(Sensor_de_nivel);
  
  Serial.print("Nivel de Agua ");
  Serial.println(nivel_de_agua);
  
  if (nivel_de_agua > 400) {
    digitalWrite(bomba2, LOW);
    Serial.println("Tanque lleno");
  } else {
    digitalWrite(bomba2, HIGH);
    Serial.println("Bomba Activada");
  }
}

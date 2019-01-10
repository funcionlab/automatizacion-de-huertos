//El monitor serial debe estar Sin ajuste de linea y a 9600 baudios
String cadena;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  
  Serial.println("Escribe los comandos: encender, apagar");
}

void loop() {
  while(Serial.available()) { 
    //Si el Puerto está disponible  
    //Leemos la cadena de caracteres del puerto serie
    cadena = Serial.readString();
    
    if (cadena == "encender") {
      digitalWrite(2,HIGH);

      Serial.println("RELEVADOR ENCENDIDO");
    }
    
    if (cadena == "apagar") {
      digitalWrite(2,LOW);
      Serial.println("RELEVADOR APAGADO");
    }
  }
}

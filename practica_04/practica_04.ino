int numero_de_led = 0;
char letra;

void setup() {
  Serial.begin(9600); //abre puerto serial

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.println("Escribe + para encender mas Leds");
  Serial.println("Escribe - para apagar Leds");
}

void loop() {
  while (Serial.available()) {
    //Si el Puerto está disponible
    //Leemos la letra del puerto serie
    
    letra = Serial.read();

    if (letra == '+') {

      if (Numero_de_Led <=5) {
        numero_de_led++;
      }

      if (numero_de_led == 1) {
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 2) {
        digitalWrite(3 , HIGH);
        digitalWrite(5 , HIGH);
        digitalWrite(6 , LOW);
        digitalWrite(9 , LOW);
        digitalWrite(10 , LOW);
        digitalWrite(11 , LOW);
      }

      if (numero_de_led == 3) {
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 4) {
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 5) {
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 6) {
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
      }
    }
    
    if (letra == '-') {

      if (numero_de_led > 0) {
        numero_de_led--;
      }

      if (numero_de_led == 0) {
        digitalWrite(3, 0);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 1) {
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 2) {
        digitalWrite(3, 1);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 3) {
        digitalWrite(3, 1);
        digitalWrite(5, 1);
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 4) {
        digitalWrite(3, 1);
        digitalWrite(5, 1);
        digitalWrite(6, 1);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 5) {
        digitalWrite(3, 1);
        digitalWrite(5, 1);
        digitalWrite(6, 1);
        digitalWrite(9, 1);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
      }

      if (numero_de_led == 6) {
        digitalWrite(3, 1);
        digitalWrite(5, 1);
        digitalWrite(6, 1);
        digitalWrite(9, 1);
        digitalWrite(10, 1);
        digitalWrite(11, HIGH);
      }
    }
  }
}

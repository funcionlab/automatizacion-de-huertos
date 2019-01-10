int pwm = 0;
char letra;

void setup() {
  Serial.begin(9600); //abre puerto serial
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.println("Escribe + para aumentar la iluminacion");
  Serial.println("Escribe - para disminuir la iluminacion");
}

void loop() {
  while (Serial.available()) { 
    //Si el Puerto está disponible
    //Leemos la letra del puerto serie

    letra = Serial.read();

    if (letra == '+') {
      pwm = pwm + 50;

      analogWrite(3, pwm);
      analogWrite(5, pwm);
      analogWrite(6, pwm);
      analogWrite(9, pwm);
      analogWrite(10, pwm);
      analogWrite(11, pwm);
    }

    if (letra == '-') {
      pwm = pwm - 50;

      analogWrite(3, pwm);
      analogWrite(5, pwm);
      analogWrite(6, pwm);
      analogWrite(9, pwm);
      analogWrite(10, pwm);
      analogWrite(11, pwm);
    }

    if (pwm >= 300) {
      pwm = 255 ;

      analogWrite(3, pwm);
      analogWrite(5, pwm);
      analogWrite(6, pwm);
      analogWrite(9, pwm);
      analogWrite(10, pwm);
      analogWrite(11, pwm);
    }
    
    if (pwm < 0) {
      pwm = 0 ;
      
      analogWrite(3, pwm);
      analogWrite(5, pwm);
      analogWrite(6, pwm);
      analogWrite(9, pwm);
      analogWrite(10, pwm);
      analogWrite(11, pwm);
    }
  }
}

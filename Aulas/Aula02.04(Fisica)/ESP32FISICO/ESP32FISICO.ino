/*
  Placa DOIT ESP32 DEVKIT V1
  Fazer o Upload -->


  Já existe um LED azul ligado ao pino 2
*/ 

#define LED_ONBOARD 2


void setup() {
  // Habilita porta serial com baudrate de 115200 bits/s
  //(padrão de ESP32)
  Serial.begin(115200);
  pinMode(LED_ONBOARD, OUTPUT);

}

void loop() {
  Serial.println("2TDSPK - 2025");
  //High: 3.3v -----> No arduino uno era 5v
  digitalWrite(LED_ONBOARD, HIGH);
  delay(2000);

  // Low: 0v
  digitalWrite(LED_ONBOARD, LOW);
  delay(2000);
}

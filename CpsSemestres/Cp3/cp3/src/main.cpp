/////////--------IOT--------FIAP------------///////////

#include <Arduino.h>

// Identificadores
const char* ID        = "INSIRA O ID DO SEU GRUPO";
const char* moduleID  = "INSIRA O ID DO SEU ESP32";

// Wi-Fi
const char* SSID      = "Wokwi-GUEST";
const char* PASSWORD  = "";

// MQTT Broker
const char* BROKER_MQTT  = "INSIRA O ENDEREÇO DO SEU BROKER";
const int   BROKER_PORT  = 1883;
const char* mqttUser     = "joao";
const char* mqttPassword = "joao1234";

// Tópico MQTT
#define TOPICO_PUBLISH  "INSIRA O NOME DO SEU TÓPICO"


// Configurações de Hardware

#define PIN_LED 15


void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(400);
  digitalWrite(PIN_LED, LOW);
  delay(400);
  Serial.println("piscando..questao nova 4.");
}









///// --------variação para publicar MQTT apenas se houver mudança do sensor

// // Variáveis globais para armazenar os últimos valores de temperatura e umidade
// float lastTemperature = NAN;
// float lastHumidity = NAN;
      // // Verificar se os novos valores de temperatura e umidade são diferentes dos últimos valores armazenados
      // if (sensorValues.temperature != lastTemperature || sensorValues.humidity != lastHumidity) {

        // // Atualizar os valores armazenados com os novos valores
        // lastTemperature = sensorValues.temperature;
        // lastHumidity = sensorValues.humidity;
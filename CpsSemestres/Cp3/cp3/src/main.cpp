#include <Arduino.h>
#include <WiFi.h>

// Identificadores
const char* ID = "Joao";
const char* moduleID = "Cp3 - Esp32";

// Wi-Fi
const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";

// MQTT Broker
const char* BROKER_MQTT = "191.232.34.158";
const int BROKER_PORT = 1883;
const char* MQTT_USER = "joao";
const char* MQTT_PASS = "joao1234";
const char* TOPIC = "Cp3/Mqtt";

// Configurações de Hardware
#define PIN_LED 15

// Estrutura para dados dos sensores
struct SensorData {
  float temperature;
  float humidity;
  float pressure;
  float altitude;
};

SensorData lastSentData = {NAN, NAN, NAN, NAN};
unsigned long lastSendTime = 0;
const long sendInterval = 5000;

WiFiClient espClient;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a rede: ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

String createJson(const SensorData& data) {
  String json = "{";
  json += "\"temperature\":" + String(data.temperature, 1) + ",";
  json += "\"humidity\":" + String(data.humidity, 1) + ",";
  json += "\"pressure\":" + String(data.pressure) + ",";
  json += "\"altitude\":" + String(data.altitude) + ",";
  json += "\"id\":\"" + String(ID) + "\",";
  json += "\"module\":\"" + String(moduleID) + "\"";
  json += "}";
  return json;
}

bool connectToBroker() {
  if (!espClient.connect(BROKER_MQTT, BROKER_PORT)) {
    Serial.println("Falha na conexão com o broker");
    return false;
  }
  return true;
}

void publishData(const SensorData& data) {
  String json = createJson(data);
  String mqttMsg = String("PUBLISH ") + TOPIC + "\n" + json;
  espClient.print(mqttMsg);
  Serial.println("Dados enviados: " + json);
}

SensorData generateSensorData() {
  SensorData data;
  data.temperature = random(200, 351) / 10.0;
  data.humidity = random(400, 801) / 10.0;
  data.pressure = random(980, 1051);
  data.altitude = random(0, 501);
  return data;
}

bool shouldSendData(const SensorData& newData) {
  if (isnan(lastSentData.temperature)) return true;
  if (abs(newData.temperature - lastSentData.temperature) >= 0.5) return true;
  if (abs(newData.humidity - lastSentData.humidity) >= 1.0) return true;
  if (abs(newData.pressure - lastSentData.pressure) >= 2) return true;
  if (abs(newData.altitude - lastSentData.altitude) >= 5) return true;
  if (millis() - lastSendTime > sendInterval) return true;
  return false;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  
  setup_wifi();
  randomSeed(millis()); // Corrigido: usando millis() em vez de analogRead
}

void loop() {
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  
  SensorData newData = generateSensorData();
  
  if (shouldSendData(newData)) {
    if (connectToBroker()) {
      publishData(newData);
      lastSentData = newData;
      lastSendTime = millis();
      espClient.stop();
    }
  }
  
  delay(1000);
}
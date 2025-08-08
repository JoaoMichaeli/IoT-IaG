#include <WiFi.h>

//----------------------------------------------------------
// Bibliotecas a instalar pelo Gerenciador de Bibliotecas

#include <PubSubClient.h>
#include <ArduinoJson.h>

//----------------------------------------------------------
// Definições e configurações

#define boardLED 2 // LED onboard

// Identificadores
const char* ID        = "Joao - Saes";
const char* moduleID  = "Cp3 - Esp32";

// Wi-Fi
const char* SSID      = "Wokwi-GUEST";
const char* PASSWORD  = "";

// MQTT Broker
const char* BROKER_MQTT  = "172.208.54.189";
const int   BROKER_PORT  = 1880;
const char* mqttUser     = "gs2025";
const char* mqttPassword = "q1w2e3r4";

// Tópico MQTT
#define TOPICO_PUBLISH  "Cp3/Mqtt"

//----------------------------------------------------------
// Variáveis globais

WiFiClient espClient;
PubSubClient MQTT(espClient);
char buffer[256]; // Buffer para o JSON serializado

//----------------------------------------------------------
// Conexão Wi-Fi

void initWiFi() {
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Conectando ao Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
}

void reconectaWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Reconectando Wi-Fi...");
        initWiFi();
    }
}

//----------------------------------------------------------
// Conexão MQTT

void initMQTT() {
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
    while (!MQTT.connected()) {
        Serial.println("Conectando ao Broker MQTT...");
        if (MQTT.connect(moduleID, mqttUser, mqttPassword)) {
            Serial.println("Conectado ao Broker!");
        } else {
            Serial.print("Falha na conexão. Estado: ");
            Serial.println(MQTT.state());
            delay(2000);
        }
    }
}

void verificaConexoesWiFiEMQTT() {
    reconectaWiFi();
    if (!MQTT.connected()) {
        initMQTT();
    }
    MQTT.loop();
}

//----------------------------------------------------------
// Envio e feedback

void enviaEstadoOutputMQTT() {
    MQTT.publish(TOPICO_PUBLISH, buffer);
    Serial.println("Mensagem publicada com sucesso!");
}

void piscaLed() {
    digitalWrite(boardLED, HIGH);
    delay(300);
    digitalWrite(boardLED, LOW);
}

//----------------------------------------------------------
// Setup inicial

void setup() {
    Serial.begin(115200);
    pinMode(boardLED, OUTPUT);
    digitalWrite(boardLED, LOW);
    initWiFi();    
    initMQTT();
}

//----------------------------------------------------------
// Loop principal

void loop() {
    // Verifica e mantém conexões ativas com Wi-Fi e MQTT
    verificaConexoesWiFiEMQTT();

    // Montagem do documento JSON
    StaticJsonDocument<300> doc;

    // 1. Identificação
    doc["ID"]     = ID;
    doc["Sensor"] = moduleID;

    // 2. Rede
    doc["IP"]     = WiFi.localIP();

    // 3. Dados de sensores
    // INSIRA AQUI OS DADOS DOS SEUS SENSORES
    // doc["Temperatura"] = temperatura;    

    // Serializa JSON para string
    serializeJson(doc, buffer);

    // Exibe no monitor serial
    Serial.println(buffer);

    // Envia via MQTT
    enviaEstadoOutputMQTT();

    // Feedback visual
    piscaLed();

    // Intervalo de envio
    delay(10000);
}
// Bibliotecas já instaladas
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

// Biblioteca a instalar
#include <Arduino_JSON.h>

// WiFi e Timer
const char* SECRET_SSID = "Joao";
const char* SECRET_PW = "joao1234";
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

// Buffer para armazenar o JSON
String jsonBuffer;

void setup() {
  Serial.begin(115200);

  WiFi.begin(SECRET_SSID, SECRET_PW);
  Serial.println("Conectando...");
  
  verificaWiFi();

  Serial.println("Timer programado para 10 segundos. Aguarde esse tempo para a leitura...");
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {

      String serverPath = "https://newsapi.org/v2/everything?q=tesla&apiKey=b15c5335bc7945c480f33e8a0dbdf066";

      jsonBuffer = httpGETRequest(serverPath.c_str());

      Serial.println("Resposta bruta:");
      Serial.println(jsonBuffer);

      JSONVar myObject = JSON.parse(jsonBuffer);

      // if (JSON.typeof(myObject) == "undefined") {
      //   Serial.println("Falha no formato dos dados!");
      //   return;
      // }

      // Serial.println("JSON analisado com sucesso!");
      // Serial.print("Status: ");
      // Serial.println(myObject["status"]);

      // Serial.print("Total de resultados: ");
      // Serial.println(myObject["totalResults"]);

      // JSONVar articles = myObject["articles"];
      // for (int i = 0; i < ((JSONVar)articles).length(); i++) {
      //   Serial.print("Título ");
      //   Serial.print(i + 1);
      //   Serial.print(": ");
      //   Serial.println(articles[i]["title"]);
      // }

    } else {
      Serial.println("WiFi desconectado");
    }

    lastTime = millis();
  }
}

// Função para requisição HTTPS GET com leitura do stream
String httpGETRequest(const char* serverName) {
  WiFiClientSecure client;
  client.setInsecure(); // Ignora validação do certificado

  HTTPClient https;
  https.begin(client, serverName);  // Inicia conexão HTTPS

  // Definindo um User-Agent
  https.addHeader("User-Agent", "ESP32");

  int httpResponseCode = https.GET();
  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    WiFiClient* stream = https.getStreamPtr();
    String result;
    while (stream->available()) {
      char c = stream->read();
      result += c;
    }
    payload = result;
  } else {
    Serial.print("Código de erro: ");
    Serial.println(httpResponseCode);
  }

  https.end();
  return payload;
}

// Função para conexão Wi-Fi
void verificaWiFi(){
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Tentando conectar à rede SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(SECRET_SSID, SECRET_PW);  
      Serial.print(".");
      delay(2000);     
    } 
    Serial.print("Rede conectada: ");
    Serial.println(WiFi.SSID());
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
    Serial.println("");
  }
}

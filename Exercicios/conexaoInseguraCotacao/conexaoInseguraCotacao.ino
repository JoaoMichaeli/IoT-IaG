// Módulo: DOIT ESP32 DEVKIT V1
// Porta: COM5 (USB)

// Bibliotecas já instaladas na IDE:
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

// Bibliotecas a instalar:
#include <Arduino_JSON.h>

// Credenciais da rede WiFi
const char* ssid = "Joao";
const char* password = "fiaparduino";

// Dados do timer
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

// Servidor
const char* server = "economia.awesomeapi.com.br";

WiFiClientSecure client;

// Variável que recebe a string JSON
String jsonBuffer;

void setup() {
  // Habilita o monitor serial:
  Serial.begin(115200);

  // Inicializa a conexão WiFi:
  WiFi.begin(ssid, password);
  Serial.println("Conectando...");
  while(WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }
  // Confirma a conexão:
  Serial.println("");
  Serial.print("Conectado à rede WiFi no endereço IP: ");
  Serial.println(WiFi.localIP());
  
  // Burlar o HTTPS
  Serial.print("\nBurlando a segurança...");
  client.setInsecure();  // Desabilita a verificação do certificado SSL
  if (!client.connect(server, 443)) {
    Serial.println("Falha na conexão!");
  } else {
    Serial.println("Server conectado!");
    // Fazendo a requisição
    client.println("GET /json/last/USD-BRL,EUR-BRL,BTC-BRL HTTP/1.1");
    client.println("Host: economia.awesomeapi.com.br");
    client.println("Connection: close");
    client.println();
  }
}

void loop() {
  if ((millis() - lastTime) > timerDelay) { // Verifica o timer de 10 segundos.
    // Verifica o status da conexão WiFi
    if(WiFi.status() == WL_CONNECTED){
      
      String serverPath = "https://economia.awesomeapi.com.br/last/USD-BRL,EUR-BRL,BTC-BRL";

      // Extraindo as informações da string JSON:
      jsonBuffer = httpGETRequest(serverPath.c_str());

      JSONVar myObject = JSON.parse(jsonBuffer);
  
      // JSON.typeof(jsonVar) pode ser usado para obter o tipo da variável
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Falha no formato dos dados!");
        return;
      }     

      // Retorna a string JSON obtida
      Serial.println("========================================================================");
      Serial.print("JSON object = ");
      Serial.println(myObject);
      Serial.println("========================================================================");

      // Dolar:
      Serial.print("Cotação Dolar: ");
      Serial.print(myObject["USDBRL"]["bid"]);
      Serial.println(" USD");

      // Euro:
      Serial.print("Cotação Euro: ");
      Serial.print(myObject["EURBRL"]["bid"]);
      Serial.println(" USD");

      // BitCoin:
      Serial.print("Cotação Bitcoin: ");
      Serial.print(myObject["BTCBRL"]["bid"]);
      Serial.println(" USD");
    }
    else {
      Serial.println("WiFi desconectado");
    }
    lastTime = millis(); // Reinicia o timer...
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Dados do servidor
  http.begin(client, serverName);
  
  // Envia a requisição GET
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  } else {
    Serial.print("Código de erro: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();

  return payload;
}
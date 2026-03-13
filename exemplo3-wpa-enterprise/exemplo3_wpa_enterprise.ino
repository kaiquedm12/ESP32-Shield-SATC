#include <WiFi.h>
#include "esp_wpa2.h"
#include "DHT.h"

#define DHTPIN 33
#define DHTTYPE DHT11
#define LDR_PIN 39

// Rede
const char* WIFI_SSID = "SATC 2.4";

// Credenciais WPA2 Enterprise
#define EAP_IDENTITY "SEU_USUARIO"   // substitua pelo seu usuário
#define EAP_USERNAME "SEU_USUARIO"   // substitua pelo seu usuário
#define EAP_PASSWORD "SUA_SENHA"     // substitua pela sua senha

// ThingSpeak
const char* server = "api.thingspeak.com";
String apiKey = "SUA_API_KEY";       // substitua pela sua API Key

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);


void conectarWiFiEnterprise() {

  Serial.print("Conectando ao WiFi Enterprise: ");
  Serial.println(WIFI_SSID);

  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

  WiFi.begin(WIFI_SSID, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);

  int tentativas = 0;

  while (WiFi.status() != WL_CONNECTED && tentativas < 60) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Falha ao conectar no WiFi.");
  }
}


void setup() {

  Serial.begin(115200);
  dht.begin();
  delay(500);

  Serial.println("ESP32 + WPA2 Enterprise + Sensores");

  conectarWiFiEnterprise();
}

void loop() {
  int luminosidade = analogRead(LDR_PIN);
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler DHT11");
    delay(2000);
    return;
  }

  Serial.println("Enviando dados para ThingSpeak...");

  if (client.connect(server, 80)) {

    String url = "/update?api_key=" + apiKey + "&field1=" + String(luminosidade) + "&field2=" + String(temperatura) + "&field3=" + String(umidade);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: api.thingspeak.com\r\n" + "Connection: close\r\n\r\n");

    Serial.println("Dados enviados!");
  } else {
    Serial.println("Falha na conexão com ThingSpeak");
  }

  client.stop();

  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("Umidade: ");
  Serial.println(umidade);

  Serial.println("-----------------------");

  delay(20000);  // mínimo 15s para ThingSpeak
}

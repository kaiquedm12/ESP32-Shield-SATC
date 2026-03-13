#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 33
#define DHTTYPE DHT11
#define LDR_PIN 39

const char* ssid     = "SEU_SSID";        // substitua pelo seu SSID
const char* password = "SUA_SENHA";       // substitua pela sua senha

const char* server = "api.thingspeak.com";
String apiKey = "SUA_API_KEY";            // substitua pela sua API Key

WiFiClient client;

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando ao WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi caiu. Reconectando...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("Reconectado!");
  }

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

    String url = "/update?api_key=" + apiKey +
                 "&field1=" + String(luminosidade) +
                 "&field2=" + String(temperatura) +
                 "&field3=" + String(umidade);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.thingspeak.com\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println("Dados enviados!");
  }
  else {
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

  delay(20000); // mínimo 15s para ThingSpeak
}

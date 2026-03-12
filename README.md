# ESP32-Shield-SATC

# Luminosidade (SENSOR LDR) / TEMPERATURA e UMIDADE (SENSOR DHT11)

## código

```
#include "DHT.h"

#define DHTPIN 33
#define DHTTYPE DHT11

#define LDR_PIN 39

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  // Leitura do LDR
  int valorLDR = analogRead(LDR_PIN);

  // Leitura do DHT11
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica erro de leitura
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler DHT11");
    return;
  }

  Serial.print("Luminosidade: ");
  Serial.print(valorLDR);

  Serial.print(" | Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");

  Serial.print(" | Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  delay(2000);
}

```

<img width="576" height="208" alt="image" src="https://github.com/user-attachments/assets/1a24f675-53d6-45c0-90d4-23738c4287e2" />

# LINK do THINGSPEAK
https://thingspeak.mathworks.com/channels/3297913

### código que conecta na rede e envia os dados

```
#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 33
#define DHTTYPE DHT11
#define LDR_PIN 39

const char* ssid = "satc_grupo_1";
const char* password = "vbyd411910";

const char* server = "api.thingspeak.com";
String apiKey = "E6Q6XMDMU15CSR6V";

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
```
<img width="1320" height="838" alt="image" src="https://github.com/user-attachments/assets/8c2f7f49-1b0e-4bed-8258-cd77bace58a3" />



# código conectando no WPA ENTERPRISE SATC

```
#include <WiFi.h>
#include "esp_wpa2.h"
#include "DHT.h"

#define DHTPIN 33
#define DHTTYPE DHT11
#define LDR_PIN 39

// Rede
const char* WIFI_SSID = "SATC 2.4";

// Credenciais WPA2 Enterprise
#define EAP_IDENTITY "kaique.41123"
#define EAP_USERNAME "kaique.41123"
#define EAP_PASSWORD "113485"

// ThingSpeak
const char* server = "api.thingspeak.com";
String apiKey = "E6Q6XMDMU15CSR6V";

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
```
<img width="1581" height="604" alt="image" src="https://github.com/user-attachments/assets/24daddec-bb3d-4fa6-ab33-fa573473d37b" />
<img width="1362" height="836" alt="image" src="https://github.com/user-attachments/assets/905fec50-ab4c-4a8b-819f-9c1eecd74f51" />


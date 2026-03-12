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




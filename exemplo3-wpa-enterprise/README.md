# Exemplo 3 — WiFi WPA2 Enterprise (SATC) + ThingSpeak

Este exemplo conecta o ESP32 à rede **WPA2 Enterprise** (ex.: rede institucional da SATC — "SATC 2.4") usando autenticação PEAP e envia os dados de luminosidade, temperatura e umidade para o **ThingSpeak**.

## Componentes utilizados

| Componente | Pino ESP32 |
|---|---|
| Sensor LDR | GPIO 39 (entrada analógica) |
| Sensor DHT11 | GPIO 33 |

## Dependências

- Biblioteca [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) (Adafruit)
- Biblioteca **WiFi** + **esp_wpa2** (incluídas na plataforma ESP32)

## Configuração

Antes de fazer o upload, edite as seguintes linhas no arquivo `.ino`:

```cpp
const char* WIFI_SSID = "SATC 2.4";   // SSID da rede Enterprise

#define EAP_IDENTITY "SEU_USUARIO"    // identidade EAP
#define EAP_USERNAME "SEU_USUARIO"    // nome de usuário
#define EAP_PASSWORD "SUA_SENHA"      // senha

String apiKey = "SUA_API_KEY";        // API Key do canal ThingSpeak
```

## Canal ThingSpeak

🔗 [https://thingspeak.mathworks.com/channels/3297913](https://thingspeak.mathworks.com/channels/3297913)

| Field | Dado |
|---|---|
| Field 1 | Luminosidade |
| Field 2 | Temperatura (°C) |
| Field 3 | Umidade (%) |

## Como usar

1. Instale as dependências listadas acima.
2. Abra o arquivo [`exemplo3_wpa_enterprise.ino`](./exemplo3_wpa_enterprise.ino) na Arduino IDE.
3. Preencha suas credenciais WPA2 Enterprise e a API Key.
4. Selecione a placa **ESP32 Dev Module** e a porta correta.
5. Faça o upload e abra o Monitor Serial (115200 baud).

## Imagens do resultado

<img width="1581" alt="Serial Monitor - Exemplo 3 (conexão)" src="https://github.com/user-attachments/assets/24daddec-bb3d-4fa6-ab33-fa573473d37b" />

<img width="1362" alt="ThingSpeak - Exemplo 3 (gráfico)" src="https://github.com/user-attachments/assets/905fec50-ab4c-4a8b-819f-9c1eecd74f51" />

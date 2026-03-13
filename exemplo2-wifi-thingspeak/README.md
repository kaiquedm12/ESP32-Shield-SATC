# Exemplo 2 — WiFi + Envio de Dados ao ThingSpeak

Este exemplo conecta o ESP32 a uma rede **WiFi convencional (WPA2-Personal)** e envia os dados de luminosidade (LDR), temperatura e umidade (DHT11) para o serviço de IoT **ThingSpeak** a cada 20 segundos.

## Componentes utilizados

| Componente | Pino ESP32 |
|---|---|
| Sensor LDR | GPIO 39 (entrada analógica) |
| Sensor DHT11 | GPIO 33 |

## Dependências

- Biblioteca [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) (Adafruit)
- Biblioteca **WiFi** (incluída na plataforma ESP32)

## Configuração

Antes de fazer o upload, edite as seguintes linhas no arquivo `.ino`:

```cpp
const char* ssid     = "SEU_SSID";   // nome da sua rede WiFi
const char* password = "SUA_SENHA";  // senha da sua rede WiFi
String apiKey = "SUA_API_KEY";       // API Key do canal ThingSpeak
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
2. Abra o arquivo [`exemplo2_wifi_thingspeak.ino`](./exemplo2_wifi_thingspeak.ino) na Arduino IDE.
3. Preencha suas credenciais WiFi e a API Key do ThingSpeak.
4. Selecione a placa **ESP32 Dev Module** e a porta correta.
5. Faça o upload e abra o Monitor Serial (115200 baud).

## Imagem do resultado

<img width="1320" alt="Monitor Serial - Exemplo 2" src="https://github.com/user-attachments/assets/8c2f7f49-1b0e-4bed-8258-cd77bace58a3" />

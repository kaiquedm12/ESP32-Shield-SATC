# 🛡️ ESP32 Shield SATC

Projetos desenvolvidos com a **placa ESP32 Shield SATC**, utilizando os sensores **LDR** (luminosidade) e **DHT11** (temperatura e umidade), com envio de dados para a plataforma **ThingSpeak**.

---

## 📁 Estrutura do Repositório

```
ESP32-Shield-SATC/
├── exemplo1-ldr-dht11/          # Leitura local dos sensores (Serial)
├── exemplo2-wifi-thingspeak/    # WiFi convencional + ThingSpeak
└── exemplo3-wpa-enterprise/     # WiFi WPA2 Enterprise (SATC) + ThingSpeak
```

---

## 🔧 Hardware

| Componente | Descrição |
|---|---|
| ESP32 Shield SATC | Microcontrolador principal |
| Sensor LDR | Medição de luminosidade (GPIO 39) |
| Sensor DHT11 | Temperatura e umidade (GPIO 33) |

---

## 📂 Exemplos

### [Exemplo 1 — LDR + DHT11 (Monitor Serial)](./exemplo1-ldr-dht11/)

Lê os dados dos sensores e exibe no Monitor Serial.

> **Pinos:** LDR → GPIO 39 | DHT11 → GPIO 33

<img width="576" alt="Monitor Serial - Exemplo 1" src="https://github.com/user-attachments/assets/1a24f675-53d6-45c0-90d4-23738c4287e2" />

---

### [Exemplo 2 — WiFi (WPA2-Personal) + ThingSpeak](./exemplo2-wifi-thingspeak/)

Conecta em uma rede WiFi convencional e envia os dados dos sensores para o **ThingSpeak** a cada 20 segundos.

> **Canal ThingSpeak:** 🔗 [https://thingspeak.mathworks.com/channels/3297913](https://thingspeak.mathworks.com/channels/3297913)

<img width="1320" alt="Monitor Serial - Exemplo 2" src="https://github.com/user-attachments/assets/8c2f7f49-1b0e-4bed-8258-cd77bace58a3" />

---

### [Exemplo 3 — WiFi WPA2 Enterprise (SATC) + ThingSpeak](./exemplo3-wpa-enterprise/)

Conecta na rede institucional **SATC 2.4** (WPA2 Enterprise / PEAP) e envia os dados ao **ThingSpeak**.

<img width="1581" alt="Serial Monitor - Exemplo 3 (conexão)" src="https://github.com/user-attachments/assets/24daddec-bb3d-4fa6-ab33-fa573473d37b" />

<img width="1362" alt="ThingSpeak - Exemplo 3 (gráfico)" src="https://github.com/user-attachments/assets/905fec50-ab4c-4a8b-819f-9c1eecd74f51" />

---

## 📦 Dependências

- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) — Adafruit
- Biblioteca **WiFi** (incluída na plataforma ESP32 para Arduino IDE)
- Biblioteca **esp_wpa2** (incluída na plataforma ESP32 para Arduino IDE)

---

## 🚀 Como começar

1. Instale a **Arduino IDE** com suporte ao ESP32 ([guia oficial](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)).
2. Instale a biblioteca **DHT sensor library** pelo Gerenciador de Bibliotecas da Arduino IDE.
3. Escolha o exemplo desejado na pasta correspondente, configure suas credenciais e faça o upload para o ESP32.

---

## 📜 Licença

Este repositório é de uso educacional — desenvolvido nas aulas práticas da **SATC**.


# Exemplo 1 — Luminosidade (LDR) e Temperatura/Umidade (DHT11)

Este exemplo lê os dados do sensor de luminosidade **LDR** (pino 39) e do sensor de temperatura e umidade **DHT11** (pino 33) e exibe os valores no Monitor Serial.

## Componentes utilizados

| Componente | Pino ESP32 |
|---|---|
| Sensor LDR | GPIO 39 (entrada analógica) |
| Sensor DHT11 | GPIO 33 |

## Dependências

- Biblioteca [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) (Adafruit)

## Como usar

1. Instale a biblioteca **DHT sensor library** na Arduino IDE.
2. Abra o arquivo [`exemplo1_ldr_dht11.ino`](./exemplo1_ldr_dht11.ino) na Arduino IDE.
3. Selecione a placa **ESP32 Dev Module** e a porta correta.
4. Faça o upload e abra o Monitor Serial (115200 baud).

## Saída esperada (Monitor Serial)

```
Luminosidade: 2048 | Temperatura: 25.00 °C | Umidade: 60.00 %
```

## Imagem do resultado

<img width="576" alt="Monitor Serial - Exemplo 1" src="https://github.com/user-attachments/assets/1a24f675-53d6-45c0-90d4-23738c4287e2" />

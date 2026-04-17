# Clima Monitor IoT com ESP32

## Descrição

Projeto utilizando **ESP32 + sensor DHT11/DHT22** para monitoramento de **temperatura e umidade** em tempo real via **Serial Monitor**.

O sistema realiza leituras periódicas do sensor e trata erros utilizando verificação de valores inválidos (`NaN`).

---

## Conceitos aplicados

* Leitura de sensores digitais
* Uso de bibliotecas externas
* Comunicação serial
* Tratamento de erro (`isnan`)
* Estrutura básica de firmware embarcado

---

## 🔧 Componentes

* ESP32
* Sensor DHT11 ou DHT22
* Resistor 10kΩ (pull-up)
* Jumpers
* Cabo USB

---

## Esquema de ligação

| DHT  | ESP32  |
| ---- | ------ |
| VCC  | 3.3V   |
| GND  | GND    |
| DATA | GPIO 4 |

> Observação: usar resistor de 10kΩ entre VCC e DATA (se necessário)

---

## Código

```cpp
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler o sensor!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C | Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  delay(2000);
}
```

---

## Como executar

1. Instale a Arduino IDE
2. Instale as bibliotecas:

   * DHT sensor library (Adafruit)
   * Adafruit Unified Sensor
3. Conecte o ESP32
4. Compile e envie o código
5. Abra o Monitor Serial (115200 baud)

---

## Problemas comuns

* `NaN` → erro de leitura (verifique fios e resistor)
* Sensor não responde → pino ou tipo incorreto
* Valores inconsistentes → limitação do DHT11

---

## Simulação no Wokwi

Você pode rodar esse projeto online sem precisar de hardware:

👉 [https://wokwi.com/](https://wokwi.com/)

### Como configurar:

1. Acesse o site
2. Clique em **“New Project” → ESP32**
3. Adicione o componente **DHT11**
4. Conecte:

   * VCC → 3.3V
   * GND → GND
   * DATA → GPIO 4
5. Cole o código acima
6. Clique em **Start Simulation**

 ---

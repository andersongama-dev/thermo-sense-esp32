#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float umidity = dht.readHumidity();

  if(isnan(temp) || isnan(umidity)) {
    Serial.println("Erro ao ler o sensor!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" °C | Umidade: ");
  Serial.print(umidity);
  Serial.println(" %");

  delay(2000);

}

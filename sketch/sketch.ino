#include "DHT.h"
#define DHTPIN 2 // Номер пина на плате

DHT dht(DHTPIN, DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000); // задержка
  float h = dht.readHumidity(); //влажность
  float t = dht.readTemperature(); //температура
  if (isnan(h) || isnan(t)) {  // Проверка.
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран
}

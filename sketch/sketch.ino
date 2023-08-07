#include "DHT.h"
#include <Servo.h>
#define DHTPIN 2 // Номер пина на плате
Servo servo;
DHT dht(DHTPIN, DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();
  servo.attach(9);   // класса Servo, серво присоединен к пину 9
  servo.write(0);   // Выставляем начальное положение 
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
  servo.write(360); // Поворачиваем серво на 90 градусов
  Serial.print(servo.write())
  if (h > 70.0){
      delay(1000);
      servo.write(1800);
      delay(100);
      servo.write(90);
      delay(1000);
      servo.write(0);
      delay(1000);
  }
}




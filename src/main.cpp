#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#ifndef DHTPIN
#define DHTPIN 4
#endif

#ifndef DHTTYPE
#define DHTTYPE DHT22
#endif

#ifdef SIMULATE_SENSOR
float fakeTemp = 25.0;
float fakeHum = 50.0;
#else
DHT dht(DHTPIN, DHTTYPE);
#endif

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 DHT logger starting...");
#ifndef SIMULATE_SENSOR
  dht.begin();
#endif
  randomSeed(esp_random());
}

void loop() {
#ifdef SIMULATE_SENSOR
  fakeTemp += 0.1;
  fakeHum += 0.2;
  if (fakeTemp > 30) fakeTemp = 25;
  if (fakeHum > 60) fakeHum = 50;
  float t = fakeTemp;
  float h = fakeHum;
#else
  float t = dht.readTemperature();
  float h = dht.readHumidity();
#endif

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor");
  } else {
    Serial.print("Temperature: ");
    Serial.print(t, 1);
    Serial.print(" C, Humidity: ");
    Serial.print(h, 1);
    Serial.println(" %");
  }
  delay(60000); // 1 minute
}

#include <Arduino.h>         // Core Arduino library for ESP32 functions
#include <Adafruit_Sensor.h> // Adafruit sensor library (needed by DHT)
#include <DHT.h>             // DHT sensor library for reading temperature & humidity

// Defines the pin where the DHT sensor is connected (GPIO4)
#ifndef DHTPIN
#define DHTPIN 4
#endif

// Defines the type of DHT sensor being used (DHT22)
#ifndef DHTTYPE
#define DHTTYPE DHT22
#endif

// If SIMULATE_SENSOR is defined, we use fake values instead of real hardware readings
#ifdef SIMULATE_SENSOR
float fakeTemp = 25.0;  // Starting temperature for simulation
float fakeHum = 50.0;   // Starting humidity for simulation
#else
DHT dht(DHTPIN, DHTTYPE); // Creates a DHT object to interact with the sensor
#endif

void setup() {
  Serial.begin(115200);           // Starts the Serial Monitor at 115200 baud
  delay(1000);                    // Short delay to stabilize
  Serial.println("ESP32 DHT logger starting...");
  
#ifndef SIMULATE_SENSOR
  dht.begin();                    // Initializes the DHT sensor (only if using hardware)
#endif

  // Initializes the random number generator using ESP32's hardware random value
  randomSeed(esp_random());
}

void loop() {
#ifdef SIMULATE_SENSOR
  // Simulation mode: Generates fake sensor readings
  // Gradually increase fake temperature and humidity
  fakeTemp += 0.1;
  fakeHum += 0.2;

  // Reset values once they pass upper limits to simulate cycling
  if (fakeTemp > 30) fakeTemp = 25;
  if (fakeHum > 60) fakeHum = 50;

  float t = fakeTemp; // Assigns current fake temperature
  float h = fakeHum;  // Assigns current fake humidity
#else
  // Hardware mode: Reads actual sensor values from the DHT22
  float t = dht.readTemperature(); // Reads temperature in Celsius
  float h = dht.readHumidity();    // Reads humidity in percentage
#endif

  // Check if readings are valid (sometimes DHT fails to respond)
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor");
  } else {
    // Prints temperature and humidity to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(t, 1);     // Prints temperature with 1 decimal place
    Serial.print(" C, Humidity: ");
    Serial.print(h, 1);     // Prints humidity with 1 decimal place
    Serial.println(" %");
  }

  delay(60000); // Wait 1 minute before next reading
}

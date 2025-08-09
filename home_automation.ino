#define BLYNK_PRINT Serial

// Blynk device details
#define BLYNK_TEMPLATE_ID "TMPLxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>

// WiFi credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensor pins
const int gasSensorPin = 34; // MQ-2 gas sensor (analog)
const int dhtPin = 33;       // DHT11 sensor (digital)

// DHT setup
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // Start Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Pin modes
  pinMode(gasSensorPin, INPUT);
  pinMode(dhtPin, INPUT);
  pinMode(4, OUTPUT); // LED pin

  // Start DHT
  dht.begin();

  delay(2000); // sensor stabilization
}

void loop() {
  Blynk.run();

  // Read gas value
  int gasValue = analogRead(gasSensorPin) / 5;
  Blynk.virtualWrite(V0, gasValue);

  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Gas alert
  if (gasValue > 2000) {
    Blynk.logEvent("gas_detected", "Gas alert!");
  }

  // LCD display
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("%");

  // LED ON
  digitalWrite(4, HIGH);

  delay(2000);
}
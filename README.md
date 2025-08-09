# Home Automation System (ESP32 + Blynk + IoT)

## 📌 Overview
This project is a **Home Automation System** using an **ESP32 microcontroller**, gas sensor (MQ-2), DHT11 temperature & humidity sensor, LCD display, and **Blynk IoT platform**.  
It monitors gas levels, temperature, and humidity in real-time, displays data on an LCD, and sends alerts to the Blynk app if gas levels exceed a threshold.

---

## 🛠️ Hardware Components
- **ESP32 Development Board**
- **MQ-2 Gas Sensor** – Detects LPG, smoke, and other gases.
- **DHT11 Sensor** – Measures temperature and humidity.
- **LCD 16x2 with I2C Module**
- **LED** – Indicator light
- **Breadboard & Jumper Wires**

---

## 💻 Software & Libraries
- **Arduino IDE**
- **Blynk IoT Platform**
- Libraries:
  - `BlynkSimpleEsp32.h`
  - `LiquidCrystal_I2C.h`
  - `DHT.h`
  - `WiFi.h`

---

## ⚙️ Features
- Real-time monitoring of **gas concentration**, **temperature**, and **humidity**.
- **LCD display** for local data visualization.
- **Blynk app integration** for remote monitoring.
- **Gas leak alerts** sent to the Blynk app.
- Expandable for controlling home appliances.

---
## 📷 Circuit Diagram
![Circuit Diagram](docs/circuit_diagram.jpeg)

---

## 🔧 Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/KeyurSapara/Home-Automation-ESP32.git
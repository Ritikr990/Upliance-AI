# Upliance-AI
# 🔥 Basic Heater Control System – Arduino (Wokwi Simulation)

## 📌 Overview
This project simulates a **basic heater control system** using an Arduino Uno, DHT22 temperature sensor, heater LED, and buzzer.  
It turns the heater **ON** or **OFF** based on temperature thresholds, and alerts for **overheating**.

The simulation is implemented on **[Wokwi](https://wokwi.com/)** and can be adapted for real hardware.

---

## 🛠 Features
- **Temperature-based state machine**:
  - `IDLE` – Waiting for low temperature  
  - `HEATING` – Heater ON  
  - `STABILIZING` – Heater OFF while temperature settles  
  - `TARGET_REACHED` – Desired temperature achieved  
  - `OVERHEAT` – Buzzer alert if too hot  
- Continuous temperature logging over Serial Monitor  
- Visual feedback via LED (heater) and buzzer (overheat alert)  
- Uses **10kΩ pull-up resistor** for DHT22 stability  

---

## 📂 Project Structure

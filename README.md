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
├── diagram.json # Wokwi wiring diagram
├── sketch.ino # Arduino C++ source code
└── README.md # Project documentation
---

## 📦 Components
- **Arduino Uno**
- **DHT22 Temperature & Humidity Sensor**
- **LED** (Heater indicator)
- **220Ω resistor** (LED current limiting)
- **Buzzer** (Overheat alert)
- **10kΩ resistor** (DHT22 pull-up)

---

## 🔌 Circuit Diagram
Wiring in `diagram.json`:

| Component | Pin on Arduino | Notes |
|-----------|---------------|-------|
| **DHT22 VCC** | 5V | Power |
| **DHT22 GND** | GND | Ground |
| **DHT22 DATA** | D2 | Temperature readings |
| **10kΩ Resistor** | Between DATA and 5V | Pull-up resistor |
| **Heater LED (A)** | D8 | Heater ON indicator |
| **LED (K)** | GND via 220Ω resistor | Current limiting |
| **Buzzer +** | D9 | Overheat alert |
| **Buzzer -** | GND | Ground |

---

## 🖥 How to Run in Wokwi
1. Go to [Wokwi Arduino Uno Project](https://wokwi.com/projects/new/arduino-uno)
2. Create `diagram.json` and paste the contents from this repo.
3. Create `sketch.ino` and paste the source code.
4. Click **Start Simulation**.
5. Adjust DHT22 temperature in the Wokwi editor to test:
   - **< 25°C** → Heater ON
   - **≥ 30°C** → Heater OFF
   - **≥ 40°C** → Overheat buzzer ON

---

## 📜 License
This project is open-source and can be modified or used for educational purposes.

---

## 🏗 Future Improvements
- Add **FreeRTOS** support for multitasking (temperature reading, control, logging)  
- Implement **BLE advertising** to broadcast heater state  
- Add **multiple heating profiles** with adjustable thresholds  
- Implement **overheat protection** with auto-shutdown

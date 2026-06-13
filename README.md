# Industrial Safety Monitoring & Control System

Embedded systems project using **Arduino UNO**, simulated in **SimulIDE** and programmed in **Arduino IDE**.

## 👥 Team Members
- Almas Shafqat – Roll No: 006
- Malaika Arooj – Roll No: 057
- Maryam – Roll No: 061
- Tehreem Ijaz – Roll No: 089

**Academic Year:** 2023-2027

---

## 📌 Overview
This project simulates an **Industrial Safety Monitoring and Control System** that continuously monitors temperature and gas levels, triggering visual (LED) and audio (buzzer) alarms when danger thresholds are exceeded. A manual reset button lets the operator acknowledge and clear alarms.

---

## 🎯 Objectives
- Detect dangerous temperature and gas levels using analog sensors.
- Provide LED visual warnings and buzzer audio alarms on danger detection.
- Allow manual alarm reset via push button.
- Simulate the complete system in SimulIDE.

---

## 🛠 Components Used

| Component | Qty | Purpose | Arduino Pin |
|---|---|---|---|
| Arduino UNO | 1 | Main microcontroller | — |
| Potentiometer (1kΩ) | 2 | Simulates Temperature & Gas sensors | A0, A1 |
| LED (Red) | 2 | Danger warning indicators | Pin 8, Pin 9 |
| Buzzer | 1 | Audio alarm | Pin 10 |
| Push Button | 1 | Manual alarm reset | Pin 12 |

---

## 🔌 Pin Configuration

| Signal | Pin | Direction | Description |
|---|---|---|---|
| Temperature Sensor | A0 | INPUT | Reads Potentiometer 1 |
| Gas Sensor | A1 | INPUT | Reads Potentiometer 2 |
| Temperature LED | 8 | OUTPUT | ON when temp > threshold |
| Gas LED | 9 | OUTPUT | ON when gas > threshold |
| Buzzer | 10 | OUTPUT | ON when danger detected |
| Reset Button | 12 | INPUT | Clears alarm when pressed |

---

## 🖼 Circuit Diagram
*(Insert circuit diagram image here)*

All sensor and output components are connected to the Arduino UNO as per the pin configuration above, with a shared common ground.

---

## 🔄 How It Works
- Sensors are read every 500 ms.
- Temperature > 600 → LED 1 ON + alarm.
- Gas > 600 → LED 2 ON + alarm.
- Any alarm → Buzzer ON.
- Reset button pressed → all LEDs and buzzer turn OFF.
- All readings/events are logged to the Serial Monitor.

---

## ✅ Test Results

| # | Scenario | Result | Status |
|---|---|---|---|
| 1 | Normal Operation | LEDs OFF, Buzzer silent | ✅ Pass |
| 2 | Temperature Danger | LED 1 ON, Buzzer ON | ✅ Pass |
| 3 | Gas Danger | LED 2 ON, Buzzer ON | ✅ Pass |
| 4 | Both Dangers | Both LEDs ON, Buzzer ON | ✅ Pass |
| 5 | Alarm Reset | All OFF | ✅ Pass |

---

## 🏁 Conclusion
The system successfully demonstrates core embedded safety concepts: real-time monitoring, threshold-based alarms, visual/audio alerts, and operator reset. Future enhancements could include real sensors (LM35, MQ-2), SMS/email alerts, SD card logging, and IoT-based remote monitoring.

---

## 📂 Project Files
- `Industrial_Safety_System.ino` – Arduino source code
- `Industrial_Safety_System.ino.hex` – Compiled HEX file
- `IndustrialSafety.sim1` – SimulIDE circuit file

# 🏥 Smart Gate Barrier with ESP8266

This project implements a simple gate barrier that measures distance with an HC-SR04 ultrasonic sensor.  
If an object or person is closer than 10 cm, the servo rotates 160° to open the gate and then closes after one second.

---

## 🧰 Required Parts
- ESP8266 board (NodeMCU or WeMos D1 mini)  
- HC-SR04 ultrasonic sensor  
- SG90 servo (or similar)  
- Jumper wires + breadboard or PCB  

---

## 🔌 Wiring
| HC-SR04 | ESP8266 | Note |
|---------|---------|------|
| VCC     | 5 V / 3.3 V | Power |
| GND     | GND     | Common |
| Trig    | D1      | Digital pin |
| Echo    | D2      | Digital pin |

| Servo | ESP8266 |
|-------|---------|
| VCC   | 5 V     |
| GND   | GND     |
| Signal| D3      |

> If your ESP8266 is 3.3 V logic and the servo is 5 V, power the servo from an external 5 V source.

---

## ⚙️ How it works
1. Open Serial Monitor at 9600 baud after uploading the sketch.  
2. Place your hand or any object in front of the sensor.  
3. If distance < 10 cm, the servo moves to 160° (gate open).  
4. After 1 s the servo returns to 0° (gate closed).

---

## 📝 Tips
- Change the threshold in `if (distance_cm < 10)` if needed.  
- For real-world gates, you may need a driver or relay for bigger motors.  
- To keep the gate open longer, use EEPROM or a simple state machine.

---

## 📦 Library Installation
Arduino IDE:  Tools > Manage Libraries... > Search "ESP8266Servo" > Install


---
## 📄 License
MIT – feel free to use and modify; please credit the source.

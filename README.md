
# 🎯 ESP32 BLE Air Mouse using MPU6050

A simple **Bluetooth Low Energy (BLE) Air Mouse** built using **ESP32 + MPU6050**.
Move the mouse using hand motion and click using a button.
Works on **Windows, Linux, Android** (BLE supported).

---

## ✨ Features

* BLE HID Mouse (no extra drivers)
* Smooth cursor control using gyroscope
* Adjustable sensitivity & deadzone
* Physical left-click button
* Low latency
* Lightweight and portable

---

## 🧰 Components Used

* ESP32 Dev Board
* MPU6050 (Gyroscope + Accelerometer)
* Push Button (Left Click)
* Jumper Wires
* Breadboard (optional)

---

## 🔌 Connections

### MPU6050 → ESP32

| MPU6050 | ESP32   |
| ------- | ------- |
| VCC     | 3.3V    |
| GND     | GND     |
| SDA     | GPIO 21 |
| SCL     | GPIO 22 |

### Button

| Button      | ESP32         |
| ----------- | ------------- |
| Left Click  | GPIO 19 → GND |
| Right Click | GPIO 18 → GND |

> Internal pull-up is used.

---

## 📦 Libraries Required

Install these from **Arduino Library Manager**:

* `BleMouse`
* `Adafruit MPU6050`
* `Adafruit Unified Sensor`

---

## ⚙️ How It Works

* Gyroscope **Z-axis** → Left / Right movement
* Gyroscope **X-axis** → Up / Down movement
* Deadzone removes small unwanted motion
* Button press triggers left click
* BLE makes ESP32 behave like a mouse

---

## 🧪 Sensitivity Tuning

```cpp
float sensitivityX = 6.0;   // left–right
float sensitivityY = 7.5;   // up–down
float deadzone     = 0.015;
```

Adjust these values based on hand comfort.

---

## ▶️ Usage

1. Upload the code to ESP32
2. Power the board
3. Pair **“AirMouse”** via Bluetooth
4. Move your hand → cursor moves
5. Press button → left click

---

## 🛠 Common Fixes

* Cursor inverted → flip sign in `bleMouse.move()`
* Too shaky → increase `deadzone`
* Too slow → increase sensitivity
* MPU not detected → check I2C wiring

---

## 📸 Connection Diagram

<img width="632" height="560" alt="image" src="https://github.com/user-attachments/assets/6ec8a245-08d5-4c0b-a671-0e6619eee1d2" />

---

## 🎮 Working Demo

Check out the air mouse in action playing Duck Hunt:

<img width="375" height="509" alt="Image" src="https://github.com/user-attachments/assets/a51e0ed4-da8e-437b-8ec0-8611077ec94d" />

🔗 [Watch Demo Video](./Working_Demo.mp4)

---
## 🚀 Future Improvements

* Right click & scroll
* Gesture support
* Battery + enclosure
* Kalman filter for smoother motion

---

## 👤 Author

**Rohn Eldho**
ECE Student
Embedded & FPGA Enthusiast

---

## ⭐ Star the Repo

If you found this useful, give it a ⭐ and share it 🚀

---


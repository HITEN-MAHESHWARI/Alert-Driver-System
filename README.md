# 🚗 Alert Driver System
### Smart Drowsiness Detection & Emergency Alert System

> A hardware-based safety project that detects driver drowsiness using an IR sensor embedded in goggles and activates a 3-stage escalating alert system to prevent road accidents.

---

## 👥 Group Members

| Name | Student ID | Role |
|------|-----------|------|
| Hiten Kalani | 25K-6549 | Hardware Lead |
| Danish Raheem | 25K-6514 | Code / Logic |
| Touqeer Hussain | 25K-6566 | Testing & Documentation |
| Abdul Haseeb | 25K-6569 | Circuit Design |

**Course:** Programming Fundamentals (PF)
**Submission Date:** April 2026

---

## 📌 Problem Statement

Driver drowsiness is one of the leading causes of road accidents, especially on long highway routes. This project provides a low-cost, real-time solution that monitors the driver's eye state and takes automatic action before an accident can occur.

---

## ⚙️ How It Works

The IR sensor inside the goggles continuously monitors whether the driver's eyes are open or closed. If eyes remain closed beyond a time threshold, the system escalates through 3 alert stages:

| Stage | Time Threshold | Action |
|-------|---------------|--------|
| Stage 1 | ~2 seconds | Soft single beep |
| Stage 2 | ~4 seconds | 3x loud repeated beeps |
| Stage 3 | ~6 seconds | Loud alarm + Car slows/stops + Water spray on face |

> If the driver wakes up at any stage, the system resets automatically.

---

## 🧠 Algorithm (Pseudocode)

```
BEGIN
  Initialize: blink_timer = 0, stage = 0

  LOOP forever:
    Read eye sensor

    IF eyes open:
      reset blink_timer = 0
      reset stage = 0
      turn OFF all outputs

    ELSE (eyes closed):
      blink_timer = blink_timer + 1

      IF blink_timer > 200 AND stage < 1:
        TRIGGER Stage 1 → soft beep
        stage = 1

      ELSE IF blink_timer > 400 AND stage < 2:
        TRIGGER Stage 2 → strong beep x3
        stage = 2

      ELSE IF blink_timer > 600 AND stage < 3:
        TRIGGER Stage 3 → beep + relay + water pump
        stage = 3

    delay(10ms)
  END LOOP
END
```

---

## 💻 Source Code

| File | Description |
|------|-------------|
| `alert_driver_basic.c` | Basic C code (beginner style — if/else + loops + functions only) |
| `alert_driver.c` | Arduino-compatible C code with pin definitions |

### Core Logic (C Language)

```c
while (1) {

    eye_state = read_sensor();

    if (eye_state == EYES_OPEN) {
        blink_timer = 0;
        stage = 0;
        reset_system();
    }
    else {
        blink_timer = blink_timer + 1;

        if (blink_timer > THRESHOLD_1 && stage < 1) {
            stage = 1;
            stage1_alert();   // soft beep
        }
        else if (blink_timer > THRESHOLD_2 && stage < 2) {
            stage = 2;
            stage2_alert();   // strong beep x3
        }
        else if (blink_timer > THRESHOLD_3 && stage < 3) {
            stage = 3;
            stage3_alert();   // beep + relay + water pump
        }
    }
    delay(10);
}
```

---

## 🔧 Components Used (BOM)

| # | Component | Qty |
|---|-----------|-----|
| 1 | Arduino Uno R3 | 1 | 
| 2 | IR Eye Blink Sensor Module | 1 | 
| 3 | Buzzer (Active, 5V) | 1 | 
| 4 | Relay Module (5V, 1 Channel) | 2 | 
| 5 | Mini DC Water Pump (5V/12V) | 1 |
| 6 | Water Tube + Nozzle | 1 set |
| 7 | DC Motor Driver (L298N) | 1 |
| 8 | Servo Motor (MG996R) | 1 | 
| 9 | Power Supply (12V / Adapter) | 1 | 
| 10 | Jumper Wires (Male-Female) | 1 pack |
| 11 | Breadboard (Full Size) | 1 | 
| 12 | LED Indicator (Red/Green) | 3 |
| 13 | Resistors (220Ω / 1kΩ) | Few | 
| 14 | Voltage Regulator (7805) | 2 | 
| 15 | Goggles Frame | 1 | 
| 16 | Mini Car Chassis + Wheels | 1 set |

> **Estimated Total Cost: PKR 7,000 – 12,000**
> *(Prices from Saddar Electronics Market & Hafeez Centre, Karachi)*

---

## 🛠️ Tools & Technologies

- **Arduino IDE** — Upload code to Arduino Uno
- **Dev C++ / Code::Blocks** — Test pure C logic
- **C Language** — Core programming (if/else, while loop, functions)
- **IR Sensor** — Eye state detection
- **L298N Motor Driver** — Car motor control
- **Relay Module** — Engine cut simulation

---

## 📋 Programming Concepts Used

| Concept | Where Used |
|---------|-----------|
| `while` loop | Main monitoring loop — runs forever |
| `if / else if / else` | Stage detection logic |
| Functions | `stage1_alert()`, `stage2_alert()`, `stage3_alert()`, `reset_system()` |
| Variables | `blink_timer`, `stage`, `eye_state` |
| `#define` constants | `THRESHOLD_1`, `THRESHOLD_2`, `THRESHOLD_3` |

---

## 🧪 Testing

- **Software Testing:** Logic verified in Dev C++ using `printf()` output
- **Hardware Testing:** Each component tested individually then as full system
- **Eye Simulation:** IR sensor manually covered to simulate eye closure
- **All 3 stages** triggered successfully at correct time thresholds

---

## 🚀 Future Improvements

- Camera-based Eye Aspect Ratio (EAR) detection for higher accuracy
- GSM module to send SMS alert to emergency contact
- GPS logging of vehicle location during drowsiness event
- ESP32 replacement for Wi-Fi/Bluetooth connectivity

---

## 📁 Repository Structure

```
Alert-Driver-System/
│
├── alert_driver_basic.c        ← Basic C code (beginner style)
├── alert_driver.c              ← Arduino version
├── AlertDriver_ProjectReport.docx  ← Full project report
└── README.md                   ← This file
```

---

*Project submitted for Programming Fundamentals (PF) — April 2026*

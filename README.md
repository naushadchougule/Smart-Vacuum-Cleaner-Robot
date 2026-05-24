# Smart Vacuum Cleaner Robot

![Hardware Prototype](Images/fig2_hardware_prototype.jpg)

An autonomous Smart Vacuum Cleaner Robot developed using Arduino UNO, ultrasonic sensors, DC motors, and a vacuum suction mechanism. The robot is capable of obstacle detection, autonomous navigation, and floor cleaning with minimal human intervention.

---

# 📌 Project Overview

The Smart Vacuum Cleaner Robot is an embedded systems and robotics project designed for autonomous indoor cleaning applications. The robot continuously scans the environment using ultrasonic sensing technology, detects nearby obstacles, changes direction automatically, and performs cleaning operations simultaneously.

This project demonstrates:
- Embedded Systems
- Robotics
- Sensor Interfacing
- Motor Control
- Autonomous Navigation
- Real-Time Automation

---

# 🛠️ Tech Stack

- Arduino UNO
- Embedded C
- HC-SR04 Ultrasonic Sensor
- L298N Motor Driver
- DC Motors
- Robotics
- Embedded Systems

---

# 📷 Project Images

## Fig. 1 – Block Diagram of Smart Vacuum Cleaner Robot

![Block Diagram](Images/fig1_block_diagram.png)

---

## Fig. 2 – Hardware Prototype of Smart Vacuum Cleaner Robot

![Hardware Prototype](Images/fig2_hardware_prototype.jpg)

---

# 🧠 Block Diagram Description

The Smart Vacuum Cleaner Robot consists of the following modules:

- Arduino UNO
- Ultrasonic Sensor
- Motor Driver Shield
- DC Motors
- Vacuum Suction Unit
- Battery Power Supply

The ultrasonic sensor continuously detects nearby obstacles and sends distance information to the Arduino UNO. The Arduino processes the data and controls motor movement through the motor driver module. The vacuum suction motor simultaneously performs floor cleaning operations.

---

# ⚙️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| L298N Motor Driver Shield | 1 |
| DC Motors | 4 |
| Robot Chassis | 1 |
| Wheels | 4 |
| Vacuum Suction Motor | 1 |
| Battery Pack | 1 |
| Jumper Wires | Multiple |

---

# 🔌 Circuit Connections

| Module | Arduino Pin |
|---|---|
| Ultrasonic Trigger | D9 |
| Ultrasonic Echo | D10 |
| Motor Driver IN1 | D2 |
| Motor Driver IN2 | D3 |
| Motor Driver IN3 | D4 |
| Motor Driver IN4 | D7 |
| ENA | D5 |
| ENB | D6 |

---

# 🔄 Working Principle

1. The robot starts moving forward automatically.
2. The ultrasonic sensor continuously measures front distance.
3. If an obstacle is detected:
   - Robot stops
   - Moves backward
   - Turns automatically
   - Continues navigation
4. The vacuum suction motor continuously collects dust and debris during movement.

---

# 💻 Arduino IDE Code

```cpp
#define ENA 5
#define IN1 2
#define IN2 3

#define ENB 6
#define IN3 4
#define IN4 7

#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
int distance;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  stopRobot();

  delay(2000);
}

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 20) {

    moveForward();

  } else {

    stopRobot();
    delay(300);

    moveBackward();
    delay(500);

    stopRobot();
    delay(300);

    turnRight();
    delay(600);

    stopRobot();
    delay(300);
  }
}

int getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}

void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
```

---

# 📊 Features

- Autonomous Navigation
- Obstacle Detection
- Automatic Direction Control
- Embedded System Automation
- Smart Cleaning Operation
- Low-Cost Robotic Design

---

# 🎯 Applications

- Smart Home Cleaning
- Robotics Projects
- Embedded Systems Learning
- Autonomous Navigation Systems
- Educational Demonstration

---

# 🚀 Future Enhancements

- Wi-Fi / Bluetooth Control
- Mobile App Integration
- Voice Assistant Support
- SLAM-Based Navigation
- AI Room Mapping
- Automatic Charging Dock

---

# 📂 Project Structure

```bash
Smart-Vacuum-Cleaner-Robot/
│
├── README.md
│
├── Arduino_Code/
│   └── smart_vacuum_cleaner_robot.ino
│
├── Images/
│   ├── fig1_block_diagram.png
│   └── fig2_hardware_prototype.jpg
│
└── LICENSE
```

---

# 🏆 Conclusion

The Smart Vacuum Cleaner Robot successfully demonstrates autonomous floor cleaning using embedded systems and obstacle avoidance techniques. The project integrates robotics, motor control, and sensor-based navigation into a practical smart cleaning solution.

---

# 👨‍💻 Author

**Naushad**  
Embedded Systems Engineer

---

# 📜 License

This project is licensed under the MIT License.

---

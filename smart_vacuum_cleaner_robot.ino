/*
========================================================
 SMART VACUUM CLEANER ROBOT
========================================================
 Components Used:
 - Arduino UNO
 - HC-SR04 Ultrasonic Sensor
 - L298N Motor Driver Shield
 - DC Motors
 - Vacuum Suction Motor
 - Battery Pack

 Features:
 ✔ Obstacle Detection
 ✔ Autonomous Navigation
 ✔ Forward / Backward Motion
 ✔ Left & Right Turning
 ✔ Automatic Cleaning
========================================================
*/

// ---------------- MOTOR PINS ----------------

// Left Motors
#define ENA 5
#define IN1 2
#define IN2 3

// Right Motors
#define ENB 6
#define IN3 4
#define IN4 7

// ---------------- ULTRASONIC SENSOR ----------------

#define TRIG_PIN 9
#define ECHO_PIN 10

// ---------------- VARIABLES ----------------

long duration;
int distance;

// ====================================================
// SETUP
// ====================================================

void setup() {

  // Motor Pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic Sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Serial Monitor
  Serial.begin(9600);

  // Motor Speed
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  stopRobot();

  delay(2000);
}

// ====================================================
// MAIN LOOP
// ====================================================

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  // Obstacle Detection
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

// ====================================================
// ULTRASONIC SENSOR FUNCTION
// ====================================================

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

// ====================================================
// ROBOT MOVEMENT FUNCTIONS
// ====================================================

// FORWARD
void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// BACKWARD
void moveBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// TURN RIGHT
void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// TURN LEFT
void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// STOP
void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

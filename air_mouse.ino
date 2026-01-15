#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

BleMouse bleMouse("AirMouse", "ESP32");
Adafruit_MPU6050 mpu;

// Buttons
#define LEFT_CLICK_PIN  19

// Tuning
float sensitivityX = 6.0;   // left–right (yaw)
float sensitivityY = 7.5;   // up–down (pitch)
float deadzone     = 0.015;

void setup() {
  Serial.begin(115200);

  bleMouse.begin();

  if (!mpu.begin()) {
    Serial.println("MPU6050 not detected");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  pinMode(LEFT_CLICK_PIN, INPUT_PULLUP);

  Serial.println("Air Mouse Ready");
}

void loop() {
  if (!bleMouse.isConnected()) return;

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // -------- GYRO AXES --------
  float yaw   = g.gyro.z;   // side-to-side
  float pitch = -g.gyro.x;   // up-down

  // -------- DEADZONE --------
  if (fabs(yaw)   < deadzone) yaw   = 0;
  if (fabs(pitch) < deadzone) pitch = 0;

  // -------- SCALE --------
  int dx = (int)(yaw   * sensitivityX);
  int dy = (int)(pitch * sensitivityY);

  // -------- MOVE --------
  if (dx != 0 || dy != 0) {
    bleMouse.move(-dx, dy); // invert X for natural feel
  }

   // -------- LEFT CLICK --------
  if (digitalRead(LEFT_CLICK_PIN) == LOW) {
    bleMouse.press(MOUSE_LEFT);
  } else {
    bleMouse.release(MOUSE_LEFT);
  }

  // -------- RIGHT CLICK --------
  if (digitalRead(RIGHT_CLICK_PIN) == LOW) {
    bleMouse.press(MOUSE_RIGHT);
  } else {
    bleMouse.release(MOUSE_RIGHT);
  }

  // -------- DEBUG --------
  Serial.print("dx: "); Serial.print(dx);
  Serial.print(" dy: "); Serial.println(dy);

  delay(6);
}

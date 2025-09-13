#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int buzzer = 8;
const int emgPin = A0;

void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  Serial.println("MPU6050 initialized.");
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  int emgValue = analogRead(emgPin);

  // Serial format: EMG,AX,AY,AZ,GX,GY,GZ
  Serial.print(emgValue); Serial.print(",");
  Serial.print(ax); Serial.print(",");
  Serial.print(ay); Serial.print(",");
  Serial.print(az); Serial.print(",");
  Serial.print(gx); Serial.print(",");
  Serial.print(gy); Serial.print(",");
  Serial.println(gz);

  // Buzzer logic
  if (abs(ax / 16384.0) > 1.5 || abs(ay / 16384.0) > 1.5 || emgValue > 600) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }

  delay(100);  // High sampling rate
}
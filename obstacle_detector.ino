// Motor A (Left)
#define AIN1 26
#define AIN2 27
#define PWMA 25

// Motor B (Right)
#define BIN1 33
#define BIN2 32
#define PWMB 14

// Sensors & Buzzer
#define IR_SENSOR 34
#define BUZZER 4

void setup() {
  // Motor pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // IR sensor
  pinMode(IR_SENSOR, INPUT);

  // Buzzer
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int obstacle = digitalRead(IR_SENSOR);

  if (obstacle == LOW) { // LOW means obstacle detected (depends on sensor type)
    stopMotors();
    digitalWrite(BUZZER, HIGH);
    Serial.println("Obstacle detected!");
    delay(500);
  } else {
    moveForward(200); // speed (0-255)
    digitalWrite(BUZZER, LOW);
    Serial.println("Moving forward...");
  }
}

// Function to move forward
void moveForward(int speed) {
  // Motor A
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);

  // Motor B
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}

// Function to stop motors
void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

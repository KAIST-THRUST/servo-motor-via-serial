#include <Arduino.h>
#include <Servo.h>

// Pin where the servo is connected. You can change this to any PWM pins you like.
constexpr int servoPin = 9;
Servo servo;
int pos;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
}

void loop() {
  Serial.println("Enter position: ");

  while (Serial.available() == 0)
    /* Wait for user input */ ;
  pos = Serial.readString().toInt();

  if (pos >= 0 && pos <= 180) {
    servo.write(pos);
    Serial.print("Servo turned to: ");
    Serial.println(pos);
  } else {
    Serial.println("Invalid position. Please enter a value between 0 and 180.");
  }
}

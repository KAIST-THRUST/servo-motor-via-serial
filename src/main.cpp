#include <Arduino.h>
#include <Servo.h>

/* Pin number where the servo is connected. You can change this to any other PWM pins. */
constexpr int servo_pin = 9;

/* Initial servo position, in degrees. */
constexpr int servo_initial_pos = 0;

/* Servo pulse width limits. */
constexpr int servo_min_pulse_width = 500;
constexpr int servo_max_pulse_width = 2500;

Servo servo;
int pos;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10); // low timeout for fast parsing
  servo.attach(servo_pin, servo_min_pulse_width, servo_max_pulse_width);
  servo.write(servo_initial_pos);
}

void loop() {
  Serial.println("Enter position: ");

  while (Serial.available() == 0)
    /* Wait for user input */;
  pos = Serial.parseInt();

  while (Serial.available() > 0) {
    Serial.read(); // Clear the input buffer, in case of non-numeric trailing input
  }

  if (pos >= 0 && pos <= 180) {
    servo.write(pos);
    Serial.print("Servo turned to: ");
    Serial.println(pos);
  } else {
    Serial.println("Invalid position. Please enter a value between 0 and 180.");
  }
}

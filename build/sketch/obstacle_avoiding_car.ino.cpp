#include <Arduino.h>
#line 1 "/home/kakarot/Code/projects/arduino/obstacle_avoiding_car/obstacle_avoiding_car.ino"
#define ENA_PIN 7 // Pin connected to the ENA pin L298N
#define IN1_PIN 6 // Pin connected to the IN1 pin L298N
#define IN2_PIN 5 // Pin connected to the IN2 pin L298N

boolean movingForward = true; // Variable to track direction

#line 7 "/home/kakarot/Code/projects/arduino/obstacle_avoiding_car/obstacle_avoiding_car.ino"
void setup();
#line 20 "/home/kakarot/Code/projects/arduino/obstacle_avoiding_car/obstacle_avoiding_car.ino"
void loop();
#line 7 "/home/kakarot/Code/projects/arduino/obstacle_avoiding_car/obstacle_avoiding_car.ino"
void setup() {
  // Initialize the motor pins as outputs
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  // Turn the motor on (forward direction)
  digitalWrite(ENA_PIN, HIGH);
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);

}

void loop() {
  delay(10000); // Run motor for 10 seconds
  
  //Turn the motor off
  digitalWrite(ENA_PIN, LOW);

  // Stop execution to keep the motor off
  while(true) {
    // do nothing, motor is off
  }
}


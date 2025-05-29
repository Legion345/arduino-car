// #include <Servo.h> // To use later for advanced project. Library for the Servo motor

// Pins for L298N Motor Driver
#define BACKWARDR 3 // Pin connected to the right motor 1
#define FORWARDR 4 // Pin connected to the right motor 2
#define BACKWARDL 5 // Pin connected to the left motor 1
#define FORWARDL 2 // Pin connected to the left motor 2

#define TRIGGER_PIN 12 // Pin connected to trigger
#define ECHO_PIN 13 // Pin connect to echo

long duration;
int distanceCm;

void setup() {
  // Initialize the motor pins as outputs
  pinMode(BACKWARDR, OUTPUT);
  pinMode(FORWARDR, OUTPUT);
  pinMode(BACKWARDL, OUTPUT);
  pinMode(FORWARDL, OUTPUT);

  //Initialize Ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize Ultrasonic Sensor
  Serial.begin(9600);
}

void loop() {
  if (distanceCm < 60) {
    // Stop before hitting the wall
    digitalWrite(FORWARDR, LOW);
    digitalWrite(FORWARDL, LOW);
    delay(200);
  } else {
    moveForward();
    delay(500);
  }

  // Trigger the UltraSonic Sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);


  // Read the echo pulse duration
  duration = pulseIn(ECHO_PIN, HIGH, 20000); // Timeout in case of no echo
  // Calculate the distance in cm
  distanceCm = duration * 0.0343 / 2;

  // Print measurements of distance
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

}

void moveForward() {
  digitalWrite(FORWARDR, HIGH);
  digitalWrite(FORWARDL, HIGH);
}


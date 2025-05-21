#include <ESP32Servo.h>

// Define the GPIO pin connected to the ESC's signal wire
#define ESC_PIN 13

// Create a servo object to control the ESC
Servo esc;

void setup() {
  Serial.begin(115200);
  
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  // Attach the ESC to the specified pin
  esc.attach(ESC_PIN, 1000, 2000); // Adjust pulse width range if needed
  
  Serial.println("Initializing ESC...");
  delay(1000);
  
  // Send minimum throttle to arm the ESC
  esc.writeMicroseconds(1000);
  Serial.println("Sending minimum throttle (arming)");
  delay(5000); // Wait for ESC to arm (important!)
  
  Serial.println("ESC should be armed now");
}

void loop() {
  // Rotate motor at different speeds
  Serial.println("Running motor at 50% speed");
  esc.writeMicroseconds(1500); // 1500us = neutral/mid throttle
  delay(3000);
  
  Serial.println("Running motor at 75% speed");
  esc.writeMicroseconds(1750);
  delay(3000);
  
  Serial.println("Stopping motor");
  esc.writeMicroseconds(1000); // Back to minimum throttle
  delay(3000);
}
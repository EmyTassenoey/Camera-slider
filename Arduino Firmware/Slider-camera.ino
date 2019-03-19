#define EN_PIN 10                 // LOW: Driver enabled. HIGH: Driver disabled
#define DIR_PIN 9                 // 
#define STEP_PIN 8                // Step on rising edge

#include <TMC2208Stepper.h>             // Include library
TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
// HardwareSerial0 for communication

void setup() {
  Serial.begin(115200);             // Init used serial port
  while(!Serial);                 // Wait for port to be ready

  // Prepare pins
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  driver.pdn_disable(1);              // Use PDN/UART pin for communication
  driver.I_scale_analog(0);           // Adjust current from the registers
  driver.rms_current(500);            // Set driver current 500mA
  driver.toff(0x2);               // Enable driver

  digitalWrite(EN_PIN, LOW);              // Enable driver
  digitalWrite(DIR_PIN, HIGH);
}

void loop() {
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN)); // Step
  delayMicroseconds(1000);
}

// Arduino Uno Code (ECU with GY-61)
#include <Wire.h>

#define X_AXIS_PIN A0  // GY-61 X-axis connected to A0
#define Y_AXIS_PIN A1  // GY-61 Y-axis connected to A1
#define Z_AXIS_PIN A2  // GY-61 Z-axis connected to A2

// Threshold for danger condition
#define VOLTAGE_THRESHOLD 2  
#define I2C_ADDRESS 8  // I2C address of this device

int danger = 0;  // Initialize danger variable

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud
  Wire.begin(I2C_ADDRESS);  // Initialize I2C as slave with address 8
  Wire.onRequest(sendDanger);  // Register function to send danger value
}

void loop() {
  // Read raw analog values from the X, Y, and Z axes
  int xValue = analogRead(X_AXIS_PIN);
  int yValue = analogRead(Y_AXIS_PIN);
  int zValue = analogRead(Z_AXIS_PIN);

  // Convert raw analog values to voltages
  float xVoltage = (xValue * 5.0) / 1023.0; // For 10-bit ADC with 5V reference
  float yVoltage = (yValue * 5.0) / 1023.0;
  float zVoltage = (zValue * 5.0) / 1023.0;

  // Check for danger condition
  if (xVoltage > VOLTAGE_THRESHOLD || yVoltage > VOLTAGE_THRESHOLD || zVoltage > VOLTAGE_THRESHOLD) {
    danger = 1;
  } else {
    danger = 0;
  }

  // Print data to Serial Monitor (optional for debugging)
  Serial.print("Danger: ");
  Serial.println(danger);

  Serial.print("X-axis Voltage: ");
  Serial.print(xVoltage);
  Serial.print(" V, Raw Value: ");
  Serial.print(xValue);

  Serial.print(", Y-axis Voltage: ");
  Serial.print(yVoltage);
  Serial.print(" V, Raw Value: ");
  Serial.print(yValue);

  Serial.print(", Z-axis Voltage: ");
  Serial.print(zVoltage);
  Serial.print(" V, Raw Value: ");
  Serial.println(zValue);

  // Small delay for readability
  delay(500);
}

// Function to send danger value over I2C
void sendDanger() {
  Wire.write(danger);  // Send danger variable as a single byte
}


#ifndef CONFIG_H
#define CONFIG_H

// ===============================
// Pin Definitions
// ===============================

#define RELAY_PIN 9
#define LED_PIN 8
#define BUTTON_PIN 2

// ===============================
// I2C Addresses
// ===============================

#define ACCEL_ADDR  0x4C
#define HP206C_ADDR 0x76

// ===============================
// Thresholds
// ===============================

#define PRESSURE_THRESHOLD 1000.0
#define ACCEL_THRESHOLD 0.5

// ===============================
// Deployment Pulse Duration
// ===============================

#define DEPLOYMENT_TIME_MS 250

#endif
#include <Arduino.h>
#include <Wire.h>

#include "pressure_sensor.h"
#include "config.h"

#define HP206C_CMD_SOFT_RESET 0x06
#define HP206C_CMD_ADC_CVT    0x40
#define HP206C_CMD_READ_P     0x30

void initializePressureSensor() {

    Wire.beginTransmission(HP206C_ADDR);

    Wire.write(HP206C_CMD_SOFT_RESET);

    Wire.endTransmission();

    delay(100);

    Serial.println("HP206C Initialized");
}

float readPressure() {

    // Start pressure conversion
    Wire.beginTransmission(HP206C_ADDR);

    Wire.write(HP206C_CMD_ADC_CVT | 0x00);

    Wire.endTransmission();

    delay(50);

    // Read pressure
    Wire.beginTransmission(HP206C_ADDR);

    Wire.write(HP206C_CMD_READ_P);

    Wire.endTransmission();

    Wire.requestFrom(HP206C_ADDR, 3);

    if (Wire.available() < 3) {

        Serial.println("Pressure Read Failed");

        return -1;
    }

    long pressure_raw = 0;

    pressure_raw |= Wire.read();
    pressure_raw <<= 8;

    pressure_raw |= Wire.read();
    pressure_raw <<= 8;

    pressure_raw |= Wire.read();

    pressure_raw &= 0x00FFFFFF;

    float pressure_hpa =
        pressure_raw / 100.0;

    return pressure_hpa;
}

bool detectSubmersion(float pressure) {

    return pressure > PRESSURE_THRESHOLD;
}
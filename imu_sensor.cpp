#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "imu_sensor.h"
#include "config.h"

static float previousMagnitude = 0.0;

void initializeIMU() {

    // Put accelerometer into active mode

    Wire.beginTransmission(ACCEL_ADDR);

    Wire.write(0x07);

    Wire.write(0x01);

    Wire.endTransmission(true);

    delay(100);

    Serial.println("Accelerometer Initialized");
}

int8_t convert6BitToSigned(byte data) {

    data &= 0x3F;

    if (data & 0x20) {

        data |= 0xC0;
    }

    return (int8_t)data;
}

IMUData readIMU() {

    IMUData imu;

    imu.ax = 0.0;
    imu.ay = 0.0;
    imu.az = 0.0;
    imu.magnitude = 0.0;

    Wire.beginTransmission(ACCEL_ADDR);

    Wire.write(0x00);

    Wire.endTransmission(false);

    Wire.requestFrom(ACCEL_ADDR, 3, true);

    if (Wire.available() < 3) {

        Serial.println("Accelerometer Read Failed");

        return imu;
    }

    byte rawX = Wire.read();
    byte rawY = Wire.read();
    byte rawZ = Wire.read();

    int8_t x = convert6BitToSigned(rawX);
    int8_t y = convert6BitToSigned(rawY);
    int8_t z = convert6BitToSigned(rawZ);

    imu.ax = x / 21.0;
    imu.ay = y / 21.0;
    imu.az = z / 21.0;

    imu.magnitude =
        sqrt(
            imu.ax * imu.ax +
            imu.ay * imu.ay +
            imu.az * imu.az
        );

    Serial.print("AX: ");
    Serial.print(imu.ax);

    Serial.print(" | AY: ");
    Serial.print(imu.ay);

    Serial.print(" | AZ: ");
    Serial.print(imu.az);

    Serial.print(" | Magnitude: ");
    Serial.println(imu.magnitude);

    return imu;
}

bool detectAbnormalOrientation(IMUData imu) {

    return
        abs(imu.ax) > 0.8 ||
        abs(imu.ay) > 0.8;
}

bool detectSporadicMotion(IMUData imu) {

    float delta =
        abs(
            imu.magnitude -
            previousMagnitude
        );

    previousMagnitude =
        imu.magnitude;

    return
        delta > ACCEL_THRESHOLD;
}
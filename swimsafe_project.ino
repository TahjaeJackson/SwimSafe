"""
Name: Tahjae Jackson 
Date: May 11, 2026
Description: swimsafe master file to controlls the overall logic of the electronic compenents of swimsafe 
"""

#include <Wire.h>

#include "config.h"

#include "imu_sensor.h"
#include "pressure_sensor.h"
#include "deployment.h"
#include "button_input.h"
#include "detection.h"

void setup() {

    Serial.begin(115200); // baud rate for the board

    Wire.begin();

    initializeIMU();

    initializePressureSensor();

    initializeDeployment();

    initializeButton();

    Serial.println("System Ready");
}

void loop() {

    if (systemDeployed()) {
        return;
    }

    bool buttonPressed =
        readButton();

    float pressure =
        readPressure();

    IMUData imu =
        readIMU();

    bool drowningDetected =
        detectDrowning(
            pressure,
            imu
        );

    //Output to debug the functionality of the electronic components

    Serial.print("Pressure: ");
    Serial.print(pressure);

    Serial.print(" | AX: ");
    Serial.print(imu.ax);

    Serial.print(" | AY: ");
    Serial.print(imu.ay);

    Serial.print(" | AZ: ");
    Serial.print(imu.az);

    Serial.print(" | Magnitude: ");

    Serial.print(imu.magnitude);

    Serial.print(" | Button: ");
    Serial.print(buttonPressed);

    Serial.print(" | Drowning: ");
    Serial.println(drowningDetected);

    // Deployment Logic

    if (
        buttonPressed ||
        drowningDetected
    ) {

        deploySystem();
    }

    delay(100);
}
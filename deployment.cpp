#include <Arduino.h>

#include "deployment.h"
#include "config.h"

static bool deployed = false;

void initializeDeployment() {

    pinMode(RELAY_PIN, OUTPUT);

    pinMode(LED_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, LOW);

    digitalWrite(LED_PIN, LOW);

    Serial.println("Deployment System Initialized");
}

// controls the output logic of the arduino nano

void deploySystem() {

    if (deployed) {
        return;
    }

    Serial.println("DEPLOYMENT ACTIVATED");

    // turn LED on permanently

    digitalWrite(LED_PIN, HIGH);

    // pulse relay once for solenoid deployment

    digitalWrite(RELAY_PIN, HIGH);

    delay(DEPLOYMENT_TIME_MS);

    digitalWrite(RELAY_PIN, LOW);

    deployed = true;

    Serial.println("System Latched");
}

// gets the current state of the system
// to ensure it is only deployed once

bool systemDeployed() {

    return deployed;
}
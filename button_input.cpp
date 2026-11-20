// This file serves as the cpp file for the button input module. It is what controls the logic of the manual activation 

#include <Arduino.h>

#include "button_input.h"
#include "config.h"

void initializeButton() {

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.println("Button Initialized");
}

bool readButton() {

    return digitalRead(BUTTON_PIN) == LOW;
}
#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

void initializePressureSensor();

float readPressure();

bool detectSubmersion(float pressure);

#endif
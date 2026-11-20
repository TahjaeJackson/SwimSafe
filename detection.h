#ifndef DETECTION_H
#define DETECTION_H

#include "imu_sensor.h"

bool detectDrowning(
    float pressure,
    IMUData imu
);

#endif
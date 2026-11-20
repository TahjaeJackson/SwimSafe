#include <Arduino.h>

#include "detection.h"

#include "imu_sensor.h"
#include "pressure_sensor.h"

bool detectDrowning(
    float pressure,
    IMUData imu
) {

    bool underwater =
        detectSubmersion(pressure);

    bool abnormalOrientation =
        detectAbnormalOrientation(imu);

    bool sporadicMotion =
        detectSporadicMotion(imu);

    return
        underwater &&
        abnormalOrientation &&
        sporadicMotion;
}
#ifndef IMU_SENSOR_H
#define IMU_SENSOR_H

struct IMUData {

    float ax;
    float ay;
    float az;

    float magnitude;
};

void initializeIMU();

IMUData readIMU();

bool detectAbnormalOrientation(IMUData imu);

bool detectSporadicMotion(IMUData imu);

#endif
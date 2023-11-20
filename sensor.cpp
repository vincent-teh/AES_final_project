#include "sensors.h"


void UltrasonicSensor::read_loop()
{
    while (1) {
        long distance = m_sensor.distance();
        if (distance == FAIL)
            printf("The ultrasonic sensor didn't work\n");
        m_distance = distance;
        ThisThread::sleep_for(DELAY_RATE);
    }
}

void LightSensor::read_loop()
{
    while (1) {
        m_light = m_sensor.read_voltage();
        ThisThread::sleep_for(DELAY_RATE);
    }
}

void TemperatureSensor::read_loop()
{
    while (1) {
        float val = m_sensor.gettemp(0);
        m_val = val ? val : -1;
        ThisThread::sleep_for(DELAY_RATE);
    }
}

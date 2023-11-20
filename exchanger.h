#ifndef H_EXCHANGE_H
#define H_EXCHANGE_H

#include "mbed.h"
#include "sensors.h"
#include "drivers.h"


#define EXCHANGE_TIME 1s

class Exchanger
{ 
public:
    Exchanger(Sensor *sensor, Driver *driver, Callback<bool(double)> to_on)
    : m_sensor(sensor), m_driver(driver), m_to_on(to_on) {}

    void exchange_loop();

private:
    Sensor* m_sensor;
    Driver* m_driver;
    Callback<bool(double)> m_to_on;
};
#endif
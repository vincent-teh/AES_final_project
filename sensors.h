#ifndef H_SENSORS_H
#define H_SENSORS_H

#include "HCSR04.h"
#include "mbed.h"
#include "max6675.h"


#define DELAY_RATE 1s
#define FAIL 1

class Sensor
{
public:
    virtual void read_loop();
    virtual double get_val();
};


class UltrasonicSensor: public Sensor {
public:
    UltrasonicSensor(PinName trig_pin, PinName echo_pin)
      : m_sensor(trig_pin, echo_pin, 1000) {}

    void read_loop();
    double get_val() {return m_distance;}

private:
    HCSR04 m_sensor;
    double m_distance = 0.0;
};

class LightSensor : public Sensor 
{
public:
    LightSensor(PinName pin): m_sensor(pin, 3.3) {}
    void read_loop();
    double get_val() {return m_light;}

private:
    AnalogIn m_sensor;
    double m_light;
};


class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor(PinName miso, PinName sck, PinName cs): m_sensor(miso, sck, cs) {}
    void read_loop();
    double get_val() {return m_val;}

private:
    max6675 m_sensor;
    double m_val = 0;
};

#endif
#ifndef H_DRIVERS_H
#define H_DRIVERS_H

#include "Servo.h"
#include "mbed.h"

class Driver
{
public:
    virtual void switch_on(bool is_on);
};


class ServoDriver : public Driver
{
public:
    ServoDriver(PinName pin): m_servo(pin) {}
    void switch_on(bool is_on) {m_servo.write(is_on ? 1 : 0.5);};

private:
    Servo m_servo;
};

class LedDriver : public Driver
{
public:
    LedDriver(PinName pin): m_led(pin) {}
    void switch_on(bool is_on) {m_led.write(is_on ? 1 : 0);};

private:
    DigitalOut m_led;
};

#endif
#include "mbed.h"
#include "drivers.h"
#include "exchanger.h"
#include "sensors.h"


#define TRIG_PIN D9
#define ECHO_PIN D8

#define SERVO_PIN D6

#define LDR_PIN A1

#define CS_PIN D10
#define SO_PIN D12
#define SCK_PIN D13

#define LED_PIN D5


int main() {
    UltrasonicSensor    ultrasonic(TRIG_PIN, ECHO_PIN);
    LightSensor         ldr(LDR_PIN);
    TemperatureSensor   temp(SO_PIN, SCK_PIN, CS_PIN);
    ServoDriver         servo(SERVO_PIN);
    LedDriver           led(LED_PIN);

    Thread threads[5];
    threads[0].start(callback(&ultrasonic, &UltrasonicSensor::read_loop));
    threads[1].start(callback(&ldr, &LightSensor::read_loop));
    threads[2].start(callback(&temp, &TemperatureSensor::read_loop));
    
    auto led_cond = [](double val) -> bool {return val > 0.5;};
    Exchanger led_ctrl(&ldr, &led, led_cond);
    threads[3].start(callback(&led_ctrl, &Exchanger::exchange_loop));

    auto servo_cond = [](double val) -> bool {return val < 10;};
    Exchanger servo_ctrl(&ultrasonic, &servo, servo_cond);
    threads[4].start(callback(&servo_ctrl, &Exchanger::exchange_loop));


    while (1) {

        ThisThread::sleep_for(1s);
    }
}

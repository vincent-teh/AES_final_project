#include "exchanger.h"


void Exchanger::exchange_loop()
{
    while (1) {
        double val = m_sensor->get_val();
        m_driver->switch_on(m_to_on(val));
        ThisThread::sleep_for(EXCHANGE_TIME);
    }
}
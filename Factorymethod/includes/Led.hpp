#ifndef _LED_H
#define _LED_H
#include <avr/io.h>
#include "Ioutput.hpp"

/* Led red GPIO */
#define LEDRED_DIR DDRB
#define LEDRED_VALUE PORTB
#define LEDRED_PIN 7

class LED : public IOutput
{
public:
    LED();
    void TurnOn();
    void TurnOff();
};

#endif
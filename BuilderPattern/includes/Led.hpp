#ifndef _LED_H
#define _LED_H
#include <avr/io.h>

/* Led red GPIO */
#define LEDRED_DIR DDRB
#define LEDRED_VALUE PORTB
#define LEDRED_PIN 7

class LED
{
public:
    LED();
    void TurnOn();
    void TurnOff();
};

#endif
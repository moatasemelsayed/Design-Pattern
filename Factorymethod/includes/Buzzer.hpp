#ifndef _BUZZER_H
#define _BUZZER_H
#include <avr/io.h>
#include "Ioutput.hpp"
/* Buzzer GPIO */
#define BUZZER_DIR DDRC
#define BUZZER_VALUE PORTC
#define BUZZER_PIN 6

class Buzzer : public IOutput
{

public:
    Buzzer();
    void TurnOn();
    void TurnOff();
};

#endif
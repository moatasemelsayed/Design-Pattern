#include "Led.hpp"
#include "Utils.hpp"
LED::LED()
{
    SET_BIT(LEDRED_DIR, LEDRED_PIN);
}

void LED::TurnOn()
{
    SET_BIT(LEDRED_VALUE, LEDRED_PIN);
}
void LED::TurnOff()
{
    CLEAR_BIT(LEDRED_VALUE, LEDRED_PIN);
}
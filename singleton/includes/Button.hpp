#include <STD_Types.hpp>
#include <Utils.hpp>
#include <avr/io.h>
class PushButton
{
private:
    const uint8 BTN0_PIN;
    const volatile uint8 *BTN0_DT;
    volatile uint8 *BTN0_DR;

public:
    PushButton();
    bool GetValue();
};

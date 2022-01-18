#include <Button.hpp>
#include <util/delay.h>
#include <STD_Types.hpp>
PushButton::PushButton() : BTN0_PIN(7), BTN0_DR(&DDRD), BTN0_DT(&PIND)
{
    // make switch is input
    CLEAR_BIT(*BTN0_DR, BTN0_PIN);
}

bool PushButton::GetValue()
{
    bool ButtonState = true;
    if (GET_BIT(*BTN0_DT, BTN0_PIN) == false)
    {
        _delay_ms(50);
        if (GET_BIT(*BTN0_DT, BTN0_PIN) == false)
        {
            ButtonState = false;
        }
    }
    return ButtonState;
}
#include "Led.hpp"
#include "Utils.hpp"
LedDevice::LED::LED()
{
    SET_BIT(LEDRED_DIR, LEDRED_PIN);
    SET_BIT(LEDGREEN_DIR, LEDGREEN_PIN);
    SET_BIT(LEDBLUE_DIR, LEDBLUE_PIN);
    SET_BIT(LEDYELLOW_DIR, LEDYELLOW_PIN);
}

void LedDevice::LED::LED_on(LedDevice::enLedColor_t led)
{
    switch (led)
    {
    case LedDevice::LedRed:
        SET_BIT(LEDRED_VALUE, LEDRED_PIN);
        break;
    case LedDevice::LedGreen:
        SET_BIT(LEDGREEN_VALUE, LEDGREEN_PIN);
        break;
    case LedDevice::LedBlue:
        SET_BIT(LEDBLUE_VALUE, LEDBLUE_PIN);
        break;
    case LedDevice::LedYellow:
        SET_BIT(LEDYELLOW_VALUE, LEDYELLOW_PIN);
        break;

    default:
        break;
    }
}
void LedDevice::LED::LED_off(LedDevice::enLedColor_t led)
{
    switch (led)
    {
    case LedDevice::LedRed:
        CLEAR_BIT(LEDRED_VALUE, LEDRED_PIN);
        break;
    case LedDevice::LedGreen:
        CLEAR_BIT(LEDGREEN_VALUE, LEDGREEN_PIN);
        break;
    case LedDevice::LedBlue:
        CLEAR_BIT(LEDBLUE_VALUE, LEDBLUE_PIN);
        break;
    case LedDevice::LedYellow:
        CLEAR_BIT(LEDYELLOW_VALUE, LEDYELLOW_PIN);
        break;

    default:
        break;
    }
}
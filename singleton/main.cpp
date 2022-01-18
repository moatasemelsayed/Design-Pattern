#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <STD_Types.hpp>
#include <Button.hpp>
#include <Led.hpp>
#include <Parking.hpp>
int main(void)
{
        PushButton BTN;
        LedDevice::LED leds;
        ParkingCounter *carnumbers = ParkingCounter::GetInstance();
        while (1)
        {
                if (BTN.GetValue() == false)
                {
                        carnumbers->IncrementParkingCounter();
                        switch (carnumbers->getCounter())
                        {
                        case 1:
                                leds.LED_on(LedDevice::LedRed);
                                break;
                        case 2:
                                leds.LED_on(LedDevice::LedGreen);
                                break;
                        case 3:
                                leds.LED_on(LedDevice::LedBlue);
                                break;
                        case 4:
                                leds.LED_on(LedDevice::LedYellow);
                                break;

                        default:
                                break;
                        }
                        while (BTN.GetValue() == false)
                                ;
                        _delay_ms(500);
                }
        }
        return 0;
}
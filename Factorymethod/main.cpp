#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <STD_Types.hpp>
#include <Button.hpp>
#include <Buzzer.hpp>
// #include <stdlib.h>
#include <Led.hpp>
#include <OutputFactory.hpp>
int main(void)
{
        PushButton BTN;
        CreateOutputFactory factory;
        IOutput *leddev = CreateOutputFactory().GetOutputDevice(CreateOutputFactory::Ledred);
        IOutput *buzzerdev = CreateOutputFactory().GetOutputDevice(CreateOutputFactory::Speaker);
        while (1)
        {
                if (BTN.GetValue() == false)
                {
                        leddev->TurnOn();
                        buzzerdev->TurnOn();
                        while ((BTN.GetValue() == false))
                                ;
                }
                else
                {
                        leddev->TurnOff();
                        buzzerdev->TurnOff();
                }
        }
        return 0;
}
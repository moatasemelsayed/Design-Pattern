#include <OutputFactory.hpp>
#include <stdlib.h>
static LED led;
static Buzzer buzzer;
IOutput *CreateOutputFactory::GetOutputDevice(enConnectedDevices dev)
{

    if (dev == Speaker)
    {
        return &buzzer;
    }
    else if (dev == Ledred)
    {
        return &led;
    }
}
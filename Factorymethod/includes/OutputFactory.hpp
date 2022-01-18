#ifndef OUTPUT_FACTORY
#define OUTPUT_FACTORY
#include "Ioutput.hpp"
#include <Buzzer.hpp>
#include <Led.hpp>

class CreateOutputFactory
{

public:
    typedef enum
    {
        Speaker,
        Ledred

    } enConnectedDevices;
    IOutput *GetOutputDevice(enConnectedDevices dev);
};
#endif
#include "builder.hpp"
#include "string.h"
#include "STD_Types.hpp"
#include <util/delay.h>
Builder::Builder(/* args */)
{
    packet = 0;
}
void Builder::buildFrame()
{
    uint8 i = 0;
    if (*packet != 0)
    {
        while (packet[i] != '\0')
        {
            if (packet[i] == ' ')
            {
                packet[i] = ',';
            }
            i++;
        }
    }
}
char *Builder::getData(Uart &Ser)
{
    packet = Ser.GetString();
    buildFrame();
    return packet;
}
Builder::~Builder()
{
}
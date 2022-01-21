#define F_CPU 16000000UL

#include <avr/io.h>
#include <STD_Types.hpp>
#include <Button.hpp>
#include <Led.hpp>
#include "Uart.hpp"
#include "builder.hpp"
int main(void)
{

        Uart serial;
        Builder b_packet;
        serial.TransmitString("hello");
        sei();
        while (1)
        {
                char *data = b_packet.getData(serial);
                if (*data != 0)
                {
                        serial.TransmitString("recieved ");
                        serial.TransmitString(data);
                        while (1)
                                ;
                }
        }
        return 0;
}
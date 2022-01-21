#include "Uart.hpp"
#include <util/delay.h>

char FrameIsr[100] = {0};
uint8 i = 0;

ISR(USART_RXC_vect)
{
    FrameIsr[i] = UDR;
    i++;
}
Uart::Uart() : plain(FrameIsr)
{
    UCSRB |= (1 << RXEN) | (1 << TXEN);                  /* Turn on transmission and reception */
    UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); /* Use 8-bit character sizes */
    UBRRL = BAUD_PRESCALE;                               /* Load lower 8-bits of the baud rate value */
    UBRRH = (BAUD_PRESCALE >> 8);                        /* Load upper 8-bits*/
    SET_BIT(UCSRB, RXCIE);
}
void Uart::Transmitchar(char ch)
{
    while (!(UCSRA & (1 << UDRE)))
        ; /* Wait for empty transmit buffer*/
    UDR = ch;
}
void Uart::TransmitString(char *str)
{
    unsigned char j = 0;

    while (str[j] != 0) /* Send string till null */
    {
        Transmitchar(str[j]);
        j++;
    }
}

char *Uart::GetString()
{
    if (i == 100)
    {
        i = 0;
        memset(FrameIsr, 0, sizeof(FrameIsr));
    }
    else
    {
        _delay_ms(1000);
        return plain;
    }
}
Uart::~Uart()
{
}
#ifndef UART_H
#define UART_H
#include "Utils.hpp"
#include "STD_Types.hpp"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "string.h"
#include "Ifram.hpp"
#define F_CPU 16000000UL
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
class Uart
{
private:
    char *plain;

public:
    Uart();
    void Transmitchar(char ch);
    void TransmitString(char *str);
    char *GetString();
    ~Uart();
};

#endif
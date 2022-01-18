#ifndef _LED_H
#define _LED_H
#include <avr/io.h>
/* Led red GPIO */
#define LEDRED_DIR DDRB
#define LEDRED_VALUE PORTB
#define LEDRED_PIN 7
/* Led green GPIO */
#define LEDGREEN_DIR DDRA
#define LEDGREEN_VALUE PORTA
#define LEDGREEN_PIN 4
/* Led blue GPIO */
#define LEDBLUE_DIR DDRA
#define LEDBLUE_VALUE PORTA
#define LEDBLUE_PIN 5
/* Led yellow GPIO */
#define LEDYELLOW_DIR DDRA
#define LEDYELLOW_VALUE PORTA
#define LEDYELLOW_PIN 6

namespace LedDevice
{

    typedef enum
    {
        LedRed,
        LedGreen,
        LedBlue,
        LedYellow

    } enLedColor_t;
    class LED
    {
    private:
        enLedColor_t ledred;
        enLedColor_t LedGreen;
        enLedColor_t LedBlue;
        enLedColor_t LedYellow;

    public:
        LED();
        void LED_on(enLedColor_t led);
        void LED_off(enLedColor_t led);
    };
};

#endif
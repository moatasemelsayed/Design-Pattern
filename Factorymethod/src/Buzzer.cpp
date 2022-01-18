
#include "Buzzer.hpp"
#include "Utils.hpp"
Buzzer::Buzzer()
{
    SET_BIT(BUZZER_DIR, BUZZER_PIN);
}

void Buzzer::TurnOn()
{
    SET_BIT(BUZZER_VALUE, BUZZER_PIN);
}
void Buzzer::TurnOff()
{
    CLEAR_BIT(BUZZER_VALUE, BUZZER_PIN);
}
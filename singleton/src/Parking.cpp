#include "Parking.hpp"
#include <stdlib.h>
ParkingCounter *ParkingCounter::instance = 0;
// int ParkingCounter ::
ParkingCounter::ParkingCounter()
{
}
ParkingCounter *ParkingCounter::GetInstance()
{
    if (instance == 0)
    {

        instance = (ParkingCounter *)malloc(sizeof(ParkingCounter));
        if (instance == 0)
        {
            // Error handle
        }
    }

    return instance;
}
void ParkingCounter::IncrementParkingCounter()
{
    if (counter > 4)
    {
        counter = 0;
    }
    counter++;
}
void ParkingCounter::DecrementParkingCounter()
{
    counter = (counter == 0) ? (1) : (counter--);
}
int ParkingCounter::getCounter()
{
    return counter;
}
ParkingCounter::~ParkingCounter()
{
    free(instance);
}
#ifndef _PARKING_
#define _PARKING_

class ParkingCounter
{
private:
    static ParkingCounter *instance;
    ParkingCounter();

public:
    int counter;
    static ParkingCounter *GetInstance();
    void IncrementParkingCounter();
    void DecrementParkingCounter();
    int getCounter();
    ~ParkingCounter();
};
#endif
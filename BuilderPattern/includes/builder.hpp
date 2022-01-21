#ifndef BUILDER_H
#define BUILDER_H
#include "Ifram.hpp"
#include "Uart.hpp"
class Builder : public Iframe
{
private:
    char *packet;

public:
    Builder();
    void buildFrame();
    char *getData(Uart &Ser);
    ~Builder();
};

#endif
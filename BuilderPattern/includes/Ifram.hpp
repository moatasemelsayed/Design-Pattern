#ifndef IFRAME_H
#define IFRAME_H

class Iframe
{
public:
    virtual char *getData(Uart &Ser);
    virtual void buildFrame();
};
#endif
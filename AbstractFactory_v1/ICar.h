#ifndef ICAR_H
#define ICAR_H

class ICar
{
public:
    virtual ~ICar() {}

    virtual void start(void) = 0;
    virtual void drive(void) = 0;
};

#endif  //ICAR_H

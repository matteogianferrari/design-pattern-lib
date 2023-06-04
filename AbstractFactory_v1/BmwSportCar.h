#ifndef BMWSPORTCAR_H
#define BMWSPORTCAR_H

#include <mutex>
#include "ISportCar.h"

class BmwSportCar:
    public ISportCar
{
public:
    BmwSportCar();
    ~BmwSportCar() override;

    void start(void) override;
    void drive(void) override;

private:
    std::mutex _mutex;
};

#endif  //BMWSPORTCAR_H

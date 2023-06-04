#ifndef MERCEDESSPORTCAR_H
#define MERCEDESSPORTCAR_H

#include <mutex>
#include "ISportCar.h"

class MercedesSportCar:
    public ISportCar
{
public:
    MercedesSportCar();
    ~MercedesSportCar() override;

    void start(void) override;
    void drive(void) override;

private:
    std::mutex _mutex;
};

#endif  //MERCEDESSPORTCAR_H

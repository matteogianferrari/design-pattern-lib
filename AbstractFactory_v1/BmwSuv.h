#ifndef BMWSUV_H
#define BMWSUV_H

#include <mutex>
#include "ISuv.h"

class BmwSuv:
    public ISuv
{
public:
    BmwSuv();
    ~BmwSuv() override;

    void start(void) override;
    void drive(void) override;

private:
    std::mutex _mutex;
};

#endif  //BMWSUV_H

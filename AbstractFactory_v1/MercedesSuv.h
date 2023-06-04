#ifndef MERCEDESSUV_H
#define MERCEDESSUV_H

#include <mutex>
#include "ISuv.h"

class MercedesSuv:
    public ISuv
{
public:
    MercedesSuv();
    ~MercedesSuv() override;

    void start(void) override;
    void drive(void) override;

private:
    std::mutex _mutex;
};

#endif  //MERCEDESSUV_H

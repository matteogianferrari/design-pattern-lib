#include "Pizza.h"


Pizza::Pizza():
    _mutex {},
    _calories {800} //Average calories for a good italian margherita pizza
{
}


Pizza::~Pizza()
{
}


uint32_t Pizza::getCalories(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return _calories;
}

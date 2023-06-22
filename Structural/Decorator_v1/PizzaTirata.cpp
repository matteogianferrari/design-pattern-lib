#include "PizzaTirata.h"


PizzaTirata::PizzaTirata(IPizza* pPizza):
    _mutex {},
    _calories {100},    //The extra garnishes from the increased surface area
    _pPizza {pPizza}
{
}


PizzaTirata::~PizzaTirata()
{
    //Watch the function details
    delete _pPizza;
}


uint32_t PizzaTirata::getCalories(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    return _pPizza->getCalories() + _calories;  //pizza alories plus the extra
}

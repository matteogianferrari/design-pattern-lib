#include "PizzaMarinara.h"


PizzaMarinara::PizzaMarinara(IPizza* pPizza):
    _mutex {},
    _calories {-180},   //The removed mozzarella
    _pPizza {pPizza}
{
}


PizzaMarinara::~PizzaMarinara()
{
    //Watch the function details
    delete _pPizza;
}


uint32_t PizzaMarinara::getCalories(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    return _pPizza->getCalories() + _calories;  //pizza alories minus the mozzarella
}

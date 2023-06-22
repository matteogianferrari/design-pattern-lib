#include "PizzaFactory.h"


PizzaFactory::PizzaFactory():
    _mutex {}
{
}


PizzaFactory::~PizzaFactory()
{
}


IPizza* PizzaFactory::makePizza(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new Pizza {};
}

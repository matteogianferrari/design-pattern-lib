#include <thread>
#include "ICar.h"
#include "ICarFactory.h"
#include "BmwFactory.h"
#include "MercedesFactory.h"


void client1(ICarFactory* pFactory)
{
    ICar* car1 {pFactory->makeSportCar()};
    car1->start();
    car1->drive();

    ICar* car2 {pFactory->makeSuv()};
    car2->start();
    car2->drive();

    delete car1;
    delete car2;
}


void client2(ICarFactory* pFactory)
{
    ICar* car1 {pFactory->makeSportCar()};
    car1->start();
    car1->drive();

    ICar* car2 {pFactory->makeSuv()};
    car2->start();
    car2->drive();

    delete car1;
    delete car2;
}


int main(int, char**) {
    BmwFactory bmwFactory {};
    MercedesFactory mercedesFactory {};

    std::thread t1 {client1, &bmwFactory};
    std::thread t2 {client2, &mercedesFactory};

    t1.join();
    t2.join();

    return 0;
}

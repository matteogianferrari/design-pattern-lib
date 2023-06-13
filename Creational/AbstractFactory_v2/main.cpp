/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Abstract Factory" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Car "Abstract Factory" and perform actions with the cars.
 *              @n This example shows one implementation of the "Abstract Factory" design pattern.
 *              This method uses an abstract class ICarFactory with the derived classes that
 *              are related to car brands. Every car brand factory can create their version of
 *              the suv and sport car. This method uses the "factoryMethod" design pattern for
 *              creating the single object in the related family. The client code gain access
 *              to the factory with a CarFactorySingleton's function. This class implements a
 *              "Singleton" design pattern to ensure that only 1 instance of CarFactory is 
 *              created during the execution of the code.
 * 
 * @note        Use the Abstract Factory pattern when:
 *              @n -A system should be independent of how its products are created, composed
 *              and represented.
 *              @n -A system should be configured with one of multiple families of products.
 *              @n -A family of related product objects is designed to be used together,
 *              and you need to enforce this constraint.
 *              @n -You want to provide a class library of products, and you want to reveal
 *              just their interfaces, not their implementations.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "ICar.h"
#include "ICarFactory.h"
#include "CarFactorySingleton.h"
#include "BmwFactory.h"
#include "MercedesFactory.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates an suv and a sport car ad uses then.
 * 
 * @details This function uses the Car factory to create the cars of the related brand.
 *          @n Used to simulate a threaded system.
 */
void client1()
{
    std::string brand {"Bmw"};
    ICarFactory* pFactory {CarFactorySingleton::getCarFactory(brand)};

    ICar* car1 {pFactory->makeSportCar()};
    car1->start();
    car1->drive();

    ICar* car2 {pFactory->makeSuv()};
    car2->start();
    car2->drive();

    delete car1;
    delete car2;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates an suv and a sport car ad uses then.
 * 
 * @details This function uses the Car factory to create the cars of the related brand.
 *          @n Used to simulate a threaded system.
 */
void client2(void)
{
    std::string brand {"Bmw"};
    ICarFactory* pFactory {CarFactorySingleton::getCarFactory(brand)};

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
    std::thread t1 {client1};
    std::thread t2 {client2};

    t1.join();
    t2.join();

    return 0;
}
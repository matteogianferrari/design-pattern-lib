/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Builder" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Car "Builder" to create a specific car and perform actions them.
 *              @n This example shows one implementation of the "Builder" design pattern.
 *              This method uses an abstract class ICarBuilder with the derived classes that
 *              are related to car brands. Every car brand builder builds its version of the
 *              components. The client code create a concrete Builder and gain access to a
 *              Director, which is used to build the specific car.
 * 
 * @note        Use the Builder pattern when:
 *              @n -The algorithm for creating a complex object should be independent of the
 *              parts that make up the object and how they're assembled.
 *              @n -The construction process must allow different representations for
 *              the object that's constructed.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "Car.h"
#include "Director.h"
#include "BmwBuilder.h"
#include "TeslaBuilder.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that create a car using a builder and a director.
 * 
 * @details This function uses the Brand builder to create the car and performs actions.
 *          @n Used to simulate a threaded system.
 * 
 * @param   director Pointer to a Director object.
 */
void client1(Director* director)
{
    //Concrete builder creation
    BmwBuilder builder {};

    //Builder setting and car creation
    director->setBuilder(&builder);
    director->buildRaceCar();

    //Car usage, must delete the object
    Car* raceCar {builder.getCar()};
    raceCar->showPartsList();
    delete raceCar;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that create a car using a builder and a director.
 * 
 * @details This function uses the Brand builder to create the car and performs actions.
 *          @n Used to simulate a threaded system.
 * 
 * @param   director Pointer to a Director object.
 */
void client2(Director* director)
{
    //Concrete builder creation
    TeslaBuilder builder {};

    //Builder setting and car creation
    director->setBuilder(&builder);
    director->buildSportCar();

    //Car usage, must delete the object
    Car* sportCar {builder.getCar()};
    sportCar->showPartsList();
    delete sportCar;
}


int main(int argc, char** argv)
{
    Director director {nullptr};

    std::thread t1 {client1, &director};
    std::thread t2 {client2, &director};

    t1.join();
    t2.join();

    return 0;
}

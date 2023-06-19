/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Facade" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the TemperatureRecorder system "Singleton" to gain access to
 *              @n the system and insert and remove temperature data.
 *              @n This example shows one implementation of the "Facade" design pattern.
 * 
 * @note        Use the "Facade" pattern when:
 *              @n -You want to provide a simple interface to a complex subsystem.
 *              Subsystem often get more complex as they evolve. Most patterns, when applied,
 *              result in more and smaller classes. This makes the subsystem more reusable
 *              and easier to customize, but it also becomes harder to use for clients
 *              that don't need to customize it. A facade can provide a simple default view
 *              of the subsystem that is good enough for most clients. Only clients
 *              needing more customizability will need to look beyond the facade.
 *              @n -There are many dependencies between clients and the implementation
 *              classes of an abstraction. Introduce a facade to decouple the subsystem
 *              from clients and other subsystems, thereby promoting subsystem independence
 *              and portability.
 *              @n -You want to layer your subsystems. Use a facade to define an entry
 *              point to each subsystem level. If subsystems are dependent, then you can
 *              simplify the dependencies between them by making them communicate with
 *              each other solely through their facades.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "TemperatureRecorder.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that inserts a temperature in the system.
 * 
 * @details This function calls the TemperatureRecorder "Singleton" to insert data.
 *          @n Used to simulate a threaded system.
 */
void client1(void)
{
    TemperatureRecorder* system = TemperatureRecorder::getTemperatureRecorder();

    std::string timeStamp {"19/06/2023 - 22:46"};

    system->insertTemperature(timeStamp, 26);
}


/**
 * @fn      client2 
 * @brief   Function that simulates a client that inserts a temperature in the system.
 * 
 * @details This function calls the TemperatureRecorder "Singleton" to insert data.
 *          @n Used to simulate a threaded system.
 */
void client2(void)
{
    TemperatureRecorder* system = TemperatureRecorder::getTemperatureRecorder();

    std::string timeStamp {"19/06/2023 - 22:47"};

    system->insertTemperature(timeStamp, 25);
}


/**
 * @fn      client3
 * @brief   Function that simulates a client that removes a temperature in the system.
 * 
 * @details This function calls the TemperatureRecorder "Singleton" to remove data.
 *          @n Used to simulate a threaded system.
 */
void client3(void)
{
    TemperatureRecorder* system = TemperatureRecorder::getTemperatureRecorder();

    std::string timeStamp {"19/06/2023 - 22:47"};

    system->deleteTemperature(timeStamp);
}


int main(int argc, char** argv)
{
    //Threads creation
    std::thread t1 {client1};
    std::thread t2 {client2};
    std::thread t3 {client3};

    //Threads execution
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

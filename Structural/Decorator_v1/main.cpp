/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Decorator" design pattern.
 * @details     This application simulates a multi-thread enviroment where 4 threads
 *              @n call the Pizza Factory to create a base pizza, and some clients decorate
 *              the pizza and then perform actions.
 *              @n This example shows one implementation of the "Decorator" design pattern.
 * 
 * @note        Use the "Decorator" pattern when:
 *              @n -You want to add responsibilities to individual objects dynamically and
 *              transparently, that is, without affecting other objects.
 *              @n -You want responsibilities that can be withdrawn.
 *              @n -The extension by subclassing is impractical. Sometimes a large number
 *              of independent extensions are possible and would produce an explosion of
 *              subclasses to support every combination. Or a class definition maybe hidden
 *              or otherwise unavailable for subclassing.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "Pizza.h"
#include "PizzaFactory.h"
#include "PizzaMarinara.h"
#include "PizzaTirata.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a pizza and gets the calories.
 * 
 * @param   pFactory Pointer to a PizzaFactory instance.
 */
void client1(PizzaFactory* pFactory)
{
    PizzaMarinara pizza {pFactory->makePizza()};

    std::cout << "Client1's pizza has " << pizza.getCalories() << " calories" << std::endl;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates a pizza and gets the calories.
 * 
 * @param   pFactory Pointer to a PizzaFactory instance.
 */
void client2(PizzaFactory* pFactory)
{
    PizzaTirata pizza {pFactory->makePizza()};

    std::cout << "Client2's pizza has " << pizza.getCalories() << " calories" << std::endl;
}


/**
 * @fn      client3
 * @brief   Function that simulates a client that creates a pizza and gets the calories.
 * 
 * @param   pFactory Pointer to a PizzaFactory instance.
 */
void client3(PizzaFactory* pFactory)
{
    IPizza* pizza = pFactory->makePizza();

    std::cout << "Client3's pizza has " << pizza->getCalories() << " calories" << std::endl;
}


/**
 * @fn      client4
 * @brief   Function that simulates a client that creates a pizza and gets the calories.
 * 
 * @param   pFactory Pointer to a PizzaFactory instance.
 */
void client4(PizzaFactory* pFactory)
{
    PizzaMarinara pizza {new PizzaTirata {pFactory->makePizza()}};

    std::cout << "Client4's pizza has " << pizza.getCalories() << " calories" << std::endl;
}


int main(int, char**){
    PizzaFactory factory {};

    //Threads creation
    std::thread t1 {client1, &factory};
    std::thread t2 {client2, &factory};
    std::thread t3 {client3, &factory};
    std::thread t4 {client4, &factory};

    //Threads execution
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

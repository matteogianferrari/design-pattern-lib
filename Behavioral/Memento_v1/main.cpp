/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Memento" design pattern.
 * @details     This application simulates an enviroment where a client uses a web browser
 *              page, visiting different sites and navigating in the page history.
 *              @n This example shows one implementation of the "Memento" design pattern.
 * 
 * @note        Use the Memento pattern when:
 *              @n -A snapshot of (some portion of) an object's state must be saved so that
 *              it can be restored to that state later.
 *              @n -A direct interface to obtaining the state would expose implementation
 *              details and break the object's encapsulation.
 * 
 * @version     0.1
 * @date        2023-07-12
 * 
 * @copyright   Copyright (c) 2023
 */

#include "PageObject.h"


/**
 * @fn      client
 * @brief   Client that uses a web browser page to navigate in the web
 *          and in the page history.
 * 
 * @param   p Pointer to a PageObject object. 
 */
void client(PageObject* p)
{
    p->visit("https://github.com");
    p->goBack();
    p->goBack();
    p->visit("https://youtube.com");
    p->jumpBack(2);
}


int main(int, char**){ 
    PageObject p {};
    client(&p);

    return 0;
}

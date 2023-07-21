/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "State" design pattern.
 * @details     This application simulates an enviroment where two clients set the internal
 *              state of a character and perform actions, then they change its internal state
 *              at run-time and perform again the actions. 
 *              @n This example shows one implementation of the "State" design pattern.
 * 
 * @note        Use the "State" pattern when:
 *              @n -An object's behavior depends on its state, and it must change its
 *              behavior at run-time depending on that state.
 *              @n -Operations have large, multipart conditional statements that depend on
 *              the object's state. Often, several operations will contain this same
 *              conditional structure.
 * 
 * @version     0.1
 * @date        2023-07-21
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Alive.h"
#include "Wounded.h"
#include "Character.h"


/**
 * @fn      client1
 * @brief   Sets the internal character state at run-time and performs actions.
 * 
 * @param   c Pointer to a Character object. 
 */
void client1(Character* c)
{
    Alive state1 {0.5f};
    Wounded state2 {0.1f};

    c->setState(&state1);
    c->move();
    c->printInfo();

    c->setState(&state2);
    c->move();
    c->printInfo();
}


/**
 * @fn      client2
 * @brief   Sets the internal character state at run-time and performs actions.
 * 
 * @param   c Pointer to a Character object. 
 */
void client2(Character* c)
{
    Alive state1 {0.8f};
    Wounded state2 {0.25f};

    c->setState(&state1);
    c->move();
    c->printInfo();

    c->setState(&state2);
    c->move();
    c->printInfo();
}


int main(int argc, char** argv)
{
    Character human {"Human"};
    Character ogre {"Ogre"};

    client1(&human);
    client2(&ogre);

    return 0;
}

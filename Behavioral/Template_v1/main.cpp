/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Template" design pattern.
 * @details     This application simulates an enviroment where a client applies operations
 *              to a signal.
 *              @n This example shows one implementation of the "Template" design pattern.
 * 
 * @note        Use the "Template" pattern when:
 *              @n -You want to implement the invariant parts of an algorithm once and
 *              leave it up to subclasses to implement the behavior that can vary.
 *              @n -The common behavior among subclasses should be factored and localized
 *              in a common class to avoid code duplication.
 *              @n -You want to control subclasses extensions. You can define a template
 *              method that call "hook" operations at specific points, thereby permitting
 *              extensions only at those points.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include "ISignal.h"
#include "TtlSignal.h"
#include "CmosSignal.h"

/**
 * @fn      client
 * @brief   Function that simulates a client that prints and processes a signal.
 * 
 * @param   signal Pointer to an ISignal object.
 */
void client(ISignal* signal)
{
    std::cout << "Input signal: " << signal->getVoltage() << std::endl;
    std::cout << "Processed signal: " << signal->process() << std::endl;
}


int main(int argc, char** argv)
{
    TtlSignal s1 {5.f};
    CmosSignal s2 {3.3f};

    client(&s1);
    client(&s2);

    return 0;
}

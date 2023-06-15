/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Adapter" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n perform actions with an usb type A, where one of them is an adapter.
 *              @n This example shows one implementation of the "Adapter" design pattern.
 *              This method uses composition to implement the Adapter. It inherits
 *              from UsbTypeA (the target, a concrete interface) and the adapter has an
 *              internal pointer to an UsbTypeC object. The UsbAdapterCToA matches the
 *              target interface by calling the adaptee interface using the internal pointer.
 * 
 * @note        Use the Adapter pattern when:
 *              @n -You want to use an existing class, and its interface does not
 *              match the one you need.
 *              @n -You want to create a reusable class that cooperates with unrelated
 *              or unforeseen classes, that is, classes that don't necessarily have
 *              compatible interfaces.
 *              @n -(object adapter only) you need to use several existing subclasses,
 *              but it's unpractical to adapt their interface by subclassing every one.
 *              An object adapter can adapt the interface of its parent class.
 * 
 * @version     0.1
 * @date        2023-06-15
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "UsbTypeA.h"
#include "UsbTypeC.h"
#include "UsbAdapterCToA.h"


/**
 * @fn      client
 * @brief   Performs actions with the input usb type A object.
 * 
 * @param   usb Pointer to an UsbTypeA object.
 * @param   data Data to transfer.
 */
void client(UsbTypeA* usb, std::string data)
{
    usb->plugOriented();
    usb->dataTransfer(data);
    usb->unplugOriented();
}


int main(int argc, char** argv)
{
    UsbTypeA usb1 {};

    UsbTypeC usb2 {};
    UsbAdapterCToA adapter {&usb2};

    //Threads creation
    std::thread t1 {client, &usb1, "I'm good at programming"};
    std::thread t2 {client, &adapter, "I'm not good at programming"};

    //Threads execution
    t1.join();
    t2.join();

    return 0;
}

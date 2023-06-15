/**
 * @file        UsbTypeA.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class UsbTypeA.
 * 
 * @version     0.1
 * @date        2023-06-15
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef USBTYPEA_H
#define USBTYPEA_H

#include <string>
#include <mutex>

/**
 * @class   UsbTypeA "UsbTypeA.h" 
 * @brief   Concrete class for an usb type A.
 * 
 * @details This class represent a concrete interface.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-15
 * @version 0.1
 */
class UsbTypeA
{
public:
    /**
     * @fn      UsbTypeA
     * @brief   Construct a new Usb Type A object.
     */
    UsbTypeA();

    /**
     * @fn      ~UsbTypeA
     * @brief   Destroy the Usb Type A object.
     */
    virtual ~UsbTypeA();

    /**
     * @fn      plugOriented 
     * @brief   Plugs the usb with an orientation.
     */
    virtual void plugOriented(void);

    /**
     * @fn      unplugOriented
     * @brief   Unplugs the usb with an orientation.
     */
    virtual void unplugOriented(void);

    /**
     * @fn      dataTransfer 
     * @brief   Transfers input data via usb type A.
     * 
     * @param   data Data to transfer. 
     */
    virtual void dataTransfer(std::string data);

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
};

#endif  //USBTYPEA_H

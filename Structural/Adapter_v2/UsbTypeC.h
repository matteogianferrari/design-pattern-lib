/**
 * @file        UsbTypeC.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class UsbTypeC.
 * 
 * @version     0.1
 * @date        2023-06-15
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef USBTYPEC_H
#define USBTYPEC_H

#include <string>
#include <mutex>

/**
 * @class   UsbTypeC "UsbTypeC.h" 
 * @brief   Concrete class for an usb type C.
 * 
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-15
 * @version 0.1
 */
class UsbTypeC
{
public:
    /**
     * @fn      UsbTypeC
     * @brief   Construct a new Usb Type C object.
     */
    UsbTypeC();

    /**
     * @fn      ~UsbTypeC
     * @brief   Destroy the Usb Type C object.
     */
    ~UsbTypeC();

    /**
     * @fn      plug 
     * @brief   Plugs the usb without an orientation.
     */
    void plug(void);
    
    /**
     * @fn      unplug
     * @brief   Unplugs the usb without an orientation.
     */
    void unplug(void);

    /**
     * @fn      fastDataTransfer 
     * @brief   Transfers input data via usb type C at elevated speed.
     * 
     * @param   data Data to transfer. 
     */
    void fastDataTransfer(std::string data);

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
};

#endif  //USBTYPEC_H

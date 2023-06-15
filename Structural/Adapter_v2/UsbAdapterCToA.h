/**
 * @file        UsbAdapterCToA.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class UsbAdapterCToA.
 * 
 * @version     0.1
 * @date        2023-06-15
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef USBTYPECTOA_H
#define USBTYPECTOA_H

#include <string>
#include <mutex>
#include "UsbTypeA.h"
#include "UsbTypeC.h"

/**
 * @class   UsbAdapterCToA "UsbAdapterCToA.h" 
 * @brief   Concrete class for an adapter from usb type C to type A.
 * 
 * @details This class derives from the concrete class UsbTypeA.
 *          This implementation adapts the UsbType C interface to the UsbType A interface.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-15
 * @version 0.1
 */
class UsbAdapterCToA:
    public UsbTypeA
{
public:
    /**
     * @fn      UsbAdapterCToA
     * @brief   Construct a new Usb Adapter C To A object
     * 
     * @param   pUsb Pointer to an UsbTypeC object.
     */
    UsbAdapterCToA(UsbTypeC* pUsb);

    /**
     * @fn      ~UsbAdapterCToA
     * @brief   Destroy the Usb Adapter C To A object.
     */
    ~UsbAdapterCToA() override;

    /**
     * @fn      plugOriented 
     * @brief   Plugs the usb adapter with an orientation.
     */
    void plugOriented(void) override;
    
    /**
     * @fn      unplugOriented
     * @brief   Unplugs the usb adapter with an orientation.
     */
    void unplugOriented(void) override;

    /**
     * @fn      dataTransfer 
     * @brief   Transfers input data via usb from type C to type A at type A speed.
     * 
     * @param   data Data to transfer. 
     */
    void dataTransfer(std::string data) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
    UsbTypeC* _pUsb;    /*Pointer to an UsbTypeC object.*/
};

#endif  //USBTYPECTOA_H

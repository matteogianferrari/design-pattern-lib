/**
 * @file        TemperatureLogger.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class TemperatureLogger.
 * 
 * @version     0.1
 * @date        2023-07-03
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef TEMPERATURELOGGER_H
#define TEMPERATURELOGGER_H

#include <mutex>
#include <vector>
#include "Client.h"

/**
 * @class   TemperatureLogger "TemperatureLogger.h" 
 * @brief   Concrete class for a temperature logger.
 * 
 * @details This class implements the "Observer" design pattern.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-03
 * @version 0.1
 */
class TemperatureLogger
{
public:
    /**
     * @fn      getTemperatureLogger
     * @brief   Gets the Temperature Logger object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use a Temperature logger in its system.
     * 
     * @return TemperatureLogger* Pointer to a TemperatureLogger object. 
     */
    static TemperatureLogger* getTemperatureLogger(void);

    /**
     * @fn      TemperatureLogger
     * @brief   Copy constructor of a TemperatureLogger object.
     * 
     * @details The TemperatureLogger shouldn't be created from another TemperatureLogger object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a TemperatureLogger object.
     */
    TemperatureLogger(TemperatureLogger& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a TemperatureLogger object.
     * 
     * @details The TemperatureLogger shouldn't be created from another TemperatureLogger object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const TemperatureLogger object.
     */
    void operator=(const TemperatureLogger& obj) = delete;

    /**
     * @fn      subscribe
     * @brief   Subscribes a client object to the logger.
     * 
     * @param   client Pointer to a Client object.
     * @return  false if the client is already subscribed, true otherwise.
     */
    bool subscribe(Client* client);

    /**
     * @fn      unsubscribe
     * @brief   Unsubscribes a client object to the logger.
     * 
     * @param   client Pointer to a Client object.
     * @return  false if the client isn't already subscribed, true otherwise.
     */
    bool unsubscribe(Client* client);

    /**
     * @fn      setTemperature
     * @brief   Sets the updated temperature value.
     * 
     * @details This function notifies all the clients subscribed to the logger.
     * 
     * @param   temp Updated temperature value.
     */
    void setTemperature(float temp);

protected:
    /**
     * @fn      TemperatureLogger
     * @brief   Construct a new Temperature Logger object. 
     */
    TemperatureLogger();

    /**
     * @fn      ~TemperatureLogger
     * @brief   Destroy the Temperature Logger object. 
     */
    ~TemperatureLogger();

private:
    /**
     * @fn      notifyAll
     * @brief   Notifies all the suscribed clients with the updated temperature. 
     */
    void notifyAll(void);

    static TemperatureLogger* _pInstance;   /*Pointer to the TemperatureLogger object.*/
    static std::mutex _mutex;               /*Mutex for thread safety.*/
    std::vector<Client*> _subscribers;      /*Vector of pointer to Client object.*/
    float _data;                            /*Internal temperature value.*/
};  

#endif  //TEMPERATURELOGGER_H

/**
 * @file        Client.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete Client class.
 * 
 * @version     0.1
 * @date        2023-07-03
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CLIENT_H
#define CLIENT_H

/**
 * @class   Client "Client.h" 
 * @brief   Class that implements a basic client that gets subscribed
 *          to a Temperature logger.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-03
 * @version 0.1
 */
class Client
{
public:
    /**
     * @fn      Client
     * @brief   Construct a new Client object. 
     */
    Client();

    /**
     * @fn      ~Client
     * @brief   Destroy the Client object. 
     */
    ~Client();

    /**
     * @fn      update
     * @brief   Updates the temperature value.
     * 
     * @param   value Updated temperature value.
     */
    void update(float value);

private:
    float _temperature; /*Internal temperature variable.*/
};

#endif  //CLIENT_H

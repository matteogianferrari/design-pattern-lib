/**
 * @file        Cache.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of Cache class.
 * 
 * @version     0.1
 * @date        2023-05-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CACHE_H
#define CACHE_H

#include <cstdint>
#include <mutex>
#include <unordered_map>

/**
 * @class   Cache "Cache.h" 
 * @brief   Class that implements a basic cache memory.
 * 
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-26
 * @version 0.1
 */
class Cache
{
public:
    /**
     * @fn Cache
     * @brief Construct a new Cache object.
     */
    Cache();

    /**
     * @fn ~Cache
     * @brief Destroy the Cache object.
     */
    ~Cache();

    /**
     * @fn      putData
     * @brief   Maps the value to the key in the Cache memory.
     * 
     * @param   key String used as index in the Cache.
     * @param   value Value to insert in the Cache.
     */
    void putData(std::string key, int32_t value);

    /**
     * @fn      getData
     * @brief   Retrieves the value mapped to the key in the Cache memory.
     * 
     * @param   key String used as index in the Cache.
     * @return  int32_t The value associated to Key in the Cache if present, 0 otherwise.
     */
    int32_t getData(std::string key);

private:                   
    std::unordered_map<std::string, int32_t> _hashMap;  /*Hash map used to implement the Cache.*/
    std::mutex _mutex;                                  /*Mutex for the thread-safety.*/
};

#endif  //CACHE_H

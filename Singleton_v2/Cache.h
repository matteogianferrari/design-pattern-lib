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
     * @fn      getCache
     * @brief   Gets the Cache object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use this cache memory in its project.
     * 
     * @return  Cache* A pointer to a Cache object.
     */
    static Cache* getCache(void);

    /**
     * @fn      Cache
     * @brief   Copy constructor of a Cache object.
     * 
     * @details The Cache shouldn't be created from another Cache object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a Cache object.
     */
    Cache(Cache& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a Cache object.
     * 
     * @details The Cache shouldn't be created from another Cache object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const Cache object.
     */
    void operator=(const Cache& obj) = delete;

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

protected:
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

private:
    static std::mutex _mutex;                           /*/*Mutex for the thread-safety.*/                   
    static Cache* _pInstance;                           /*Pointer to the Cache instance.*/
    std::unordered_map<std::string, int32_t> _hashMap;  /*Hash map used to implement the Cache.*/
};

#endif  //CACHE_H

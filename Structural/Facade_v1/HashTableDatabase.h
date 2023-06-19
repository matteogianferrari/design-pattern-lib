/**
 * @file        HashTableDatabase.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class HashTableDatabase.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef HASHTABLEDATABASE_H
#define HASHTABLEDATABASE_H

#include <mutex>
#include <unordered_map>
#include "IDatabase.h"

/**
 * @class   HashTableDatabase "HashTableDatabase.h" 
 * @brief   Class that implements a database system using an hash map.
 * 
 * @details This class derives from the abstract class IDatabase.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-19
 * @version 0.1
 */
class HashTableDatabase:
    public IDatabase
{
public:
    /**
     * @fn      HashTableDatabase
     * @brief   Construct a new Hash Table Database object.
     */
    HashTableDatabase();

    /**
     * @fn      ~HashTableDatabase
     * @brief   Destroy the Hash Table Database object.
     */
    ~HashTableDatabase() override;

    /**
     * @fn      insertRecord
     * @brief   Inserts a record in the hash map database.
     * 
     * @param   key String reference used as key in the database.
     * @param   data Value to insert in the database.
     * @return  true if the record is correctly inserted, false otherwise. 
     */
    bool insertRecord(std::string& key, int32_t data) override;

    /**
     * @fn      deleteRecord
     * @brief   Removes a record in the hash map database.
     * 
     * @param   key String reference used as index in the database.
     * @return  true if the record is correctly removed, false otherwise. 
     */
    bool deleteRecord(std::string& key) override;

private:
    std::mutex _mutex;                                  /*Mutex for thread safety.*/             
    std::unordered_map<std::string, int32_t> _hashMap;  /*Hash map used to implement the database.*/
};

#endif  //HASHTABLEDATABASE_H

/**
 * @file        IDatabase.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IDatabase.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IDATABASE_H
#define IDATABASE_H

#include <string>
#include <cstdint>

/**
 * @class   IDatabase "IDatabase.h" 
 * @brief   Abstract class for a generic database system.
 * 
 * @details The implementations of this class must provide functions for inserting
 *          and removing records from the specific database system.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-19
 * @version 0.1
 */
class IDatabase
{
public:
    /**
     * @fn      ~IDatabase
     * @brief   Destroy the IDatabase object. 
     */
    virtual ~IDatabase() {}

    /**
     * @fn      insertRecord
     * @brief   Inserts a record in the database.
     * 
     * @param   key String reference used as key in the database.
     * @param   data Value to insert in the database.
     * @return  true if the record is correctly inserted, false otherwise. 
     */
    virtual bool insertRecord(std::string& key, int32_t data) = 0;

    /**
     * @fn      deleteRecord
     * @brief   Removes a record in the database.
     * 
     * @param   key String reference used as index in the database.
     * @return  true if the record is correctly removed, false otherwise. 
     */
    virtual bool deleteRecord(std::string& key) = 0; 
};

#endif  //IDATABASE_H

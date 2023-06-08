/**
 * @file        CellRegistry.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class CellRegistry.
 * 
 * @version     0.1
 * @date        2023-06-08
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CELLREGISTRY_H
#define CELLREGISTRY_H

#include <mutex>
#include <unordered_map>
#include "ICell.h"

/**
 * @class   CellRegistry "CellRegistry.h" 
 * @brief   Class that implements a cell registry.
 * 
 * @details This implementation creates a "Cell pool" of frequently used cells from which
 *          the client can create copies using the clone function "Prototype" design pattern.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-08
 * @version 0.1
 */
class CellRegistry
{
public:
    /**
     * @fn      getCellRegistry
     * @brief   Gets the CellRegistry object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use this cache memory in its project.
     * 
     * @return  CellRegistry* A pointer to a CellRegistry object.
     */
    static CellRegistry* getCellRegistry(void);

    /**
     * @fn      CellRegistry
     * @brief   Copy constructor of a CellRegistry object.
     * 
     * @details The CellRegistry shouldn't be created from another CellRegistry object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a Cache object.
     */
    CellRegistry(CellRegistry& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a CellRegistry object.
     * 
     * @details The CellRegistry shouldn't be created from another CellRegistry object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const CellRegistry object.
     */
    void operator=(const CellRegistry& obj) = delete;

    /**
     * @fn      addCell
     * @brief   Maps the cell to the key in the CellRegistry.
     * 
     * @param   key Reference to a string used as index in the CellRegistry.
     * @param   value Value to insert in the Cache.
     */
    void addCell(std::string& key, ICell* cell);

    /**
     * @fn      getData
     * @brief   Retrieves the deep copy of the selected cell in the CellRegistry.
     * 
     * @param   key Reference to a string used as index in the CellRegistry.
     * @return  ICell* A pointer to the deep copy of the cell, created with the clone function.
     *          Returns nullptr if key isn't present in the CellRegistry.
     */
    ICell* getCell(std::string& key);

protected:
    /**
     * @fn      CellRegistry
     * @brief   Construct a new CellRegistry object.
     */
    CellRegistry();

    /**
     * @fn      ~CellRegistry
     * @brief   Destroy the CellRegistry object.
     */
    ~CellRegistry();

private:
    static std::mutex _mutex;                          /*Mutex for the thread-safety.*/                   
    static CellRegistry* _pInstance;                   /*Pointer to the CellRegistry instance.*/
    std::unordered_map<std::string, ICell*> _hashMap;  /*Hash map used to implement the
                                                         CellRegistry.*/
};

#endif  //CELLREGISTRY_H

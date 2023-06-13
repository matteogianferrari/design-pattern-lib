/**
 * @file        CellSingleton.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of CellSingleton class.
 * 
 * @version     0.1
 * @date        2023-06-12
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CELLSINGLETON_H
#define CELLSINGLETON_H

#include <mutex>
#include "ICell.h"
#include "FungiCell.h"
#include "PlantCell.h"

/**
 * @class   CellSingleton "CellSingleton.h" 
 * @brief   Class that implements a cell Singleton.
 * 
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-12
 * @version 0.1
 */
class CellSingleton
{
public:
    /**
     * @fn      getCell
     * @brief   Gets the concrete Cell object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use a Cell to clone in its project.
     * 
     * @param   type The cell type to create.
     * @return  ICell* A pointer to an ICell object.
     */
    static ICell* getCell(std::string& type);

    /**
     * @fn      CellSingleton
     * @brief   Copy constructor of a CellSingleton object.
     * 
     * @details The CellSingleton shouldn't be created from another CellSingleton object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a CellSingleton object.
     */
    CellSingleton(CellSingleton& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a CellSingleton object.
     * 
     * @details The CellSingleton shouldn't be created from another CellSingleton object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const CellSingleton object.
     */
    void operator=(const CellSingleton& obj) = delete;

protected:
    /**
     * @fn      CellSingleton
     * @brief   Construct a new CellSingleton object.
     */
    CellSingleton();

    /**
     * @fn      ~CellSingelton
     * @brief   Destroy the CellSingleton object.
     */
    ~CellSingleton();

private:
    static std::mutex _mutex;   /*Mutex for the thread-safety.*/                   
    static ICell* _pInstance;   /*Pointer to the Cell instance.*/
};

#endif  //CELLSINGLETON_H

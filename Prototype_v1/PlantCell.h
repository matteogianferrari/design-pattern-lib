/**
 * @file        PlantCell.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PlantCell.
 * 
 * @version     0.1
 * @date        2023-06-07
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PLANTCELL_H
#define PLANTCELL_H

#include <mutex>
#include <string>
#include "ICell.h"

/**
 * @class   PlantCell "PlantCell.h" 
 * @brief   Class that implements a plant cell.
 * 
 * @details This class derives from the abstract class ICell.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-07
 * @version 0.1
 */
class PlantCell:
    public ICell
{
public:
    /**
     * @fn      PlantCell
     * @brief   Construct a new Plant Cell object.
     * 
     * @param   plant Reference to a string that represents the plant's type.
     */
    PlantCell(std::string& plant);

    /**
     * @fn      PlantCell
     * @brief   Copy constructor of a PlantCell object.
     * 
     * @param   cell Reference to a PlantCell object.
     */
    PlantCell(PlantCell& cell);

    /**
     * @fn      ~PlantCell
     * @brief   Destroy the Plant Cell object.
     */
    ~PlantCell() override;

    /**
     * @fn      clone
     * @brief   Creates an ICell object copying the elements from this PlantCell instance.
     * 
     * @details This function is the implementation of the "Protoype" design pattern.
     *          @n It makes a deep copy of this plant cell and returns a pointer to the new
     *          allocated object.
     * 
     * @return  ICell* A Pointer to an ICell object.
     */
    ICell* clone(void) override;

    /**
     * @fn      print
     * @brief   Outputs to the specified output stream the object's information.
     * 
     * @param   os Reference to an output stream.
     */
    void print(std::ostream& os) override;

    /**
     * @fn      photosyntesis
     * @brief   Starts the plant cell's photosyntesis process.
     */
    void photosyntesis(void);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
    std::string _plant; /*Plant cell's type.*/
};

#endif  //PLANTCELL_H

/**
 * @file        Department.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Department.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "IWorkResource.h"

/**
 * @class   Department "Department.h" 
 * @brief   Class that implements a department.
 * 
 * @details This class derives from the abstract class IWorkResource.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-04
 * @version 0.1
 */
class Department:
    public IWorkResource
{
public:
    /**
     * @fn      Department
     * @brief   Construct a new Department object.
     * 
     * @param   resourceA Pointer to an IWorkResource object.
     * @param   resourceB Pointer to an IWorkResource object.
     * @param   resourceC Pointer to an IWorkResource object.
     */
    Department(IWorkResource* resourceA, IWorkResource* resourceB, IWorkResource* resourceC);
    
    /**
     * @fn      ~Department
     * @brief   Destroy the Department object.
     */
    ~Department() override;

    /**
     * @fn      work
     * @brief   Gets the department work done.
     * 
     * @param   workLoad The project workload to substain.
     * @return  int32_t A unit of work load done.
     */
    int32_t work(int32_t workLoad) override;

    /**
     * @fn      getWorkCapability
     * @brief   Retreives the potential work that the department can substain.
     * 
     * @return  int32_t A unit of potential work load.
     */
    int32_t getWorkCapability(void) override;

private:
    bool isSubstainable(int32_t workCapability, int32_t workLoad);

    IWorkResource* _resourceA;  /*Pointer to an IWorkResource object.*/
    IWorkResource* _resourceB;  /*Pointer to an IWorkResource object.*/
    IWorkResource* _resourceC;  /*Pointer to an IWorkResource object.*/
};

#endif  //DEPARTMENT_H

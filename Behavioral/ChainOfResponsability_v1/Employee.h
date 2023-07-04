/**
 * @file        Employee.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Employee.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "IWorkResource.h"

/**
 * @class   Employee "Employee.h" 
 * @brief   Class that implements an employee.
 * 
 * @details This class derives from the abstract class IWorkResource.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-04
 * @version 0.1
 */
class Employee:
    public IWorkResource
{
public:
    /**
     * @fn      Employee
     * @brief   Construct a new Employee object.
     * 
     * @param   workLoad The employee work load capable to sustain (1 default).
     */
    Employee(int32_t workLoad = 1);

    /**
     * @fn      ~Employee
     * @brief   Destroy the Employee object.
     */
    ~Employee() override;

    /**
     * @fn      work
     * @brief   Gets the employee work done.
     * 
     * @param   workLoad The project workload to substain.
     * @return  int32_t A unit of work load done.
     */
    int32_t work(int32_t workLoad) override;

    /**
     * @fn      getWorkCapability
     * @brief   Retreives the potential work that the employee can substain.
     * 
     * @return  int32_t A unit of potential work load.
     */
    int32_t getWorkCapability(void) override;

private:
    int32_t _workLoad;  /*Employee work load capable to substain.*/
};

#endif  //EMPLOYEE_H

/**
 * @file        Company.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Company.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef COMPANY_H
#define COMPANY_H

#include <mutex>
#include "IWorkResource.h"
#include "ResourceFactory.h"

/**
 * @class   Company "Company.h" 
 * @brief   Concrete class for a company.
 * 
 * @details This class uses the "Singleton" design pattern.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-04
 * @version 0.1
 */
class Company
{
public:
    /**
     * @fn      getCompany
     * @brief   Gets the Company object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use a company in its system.
     * 
     * @return  Company* Pointer to a Company object. 
     */
    static Company* getCompany(void);

    /**
     * @fn      Company
     * @brief   Copy constructor of a Company object.
     * 
     * @details The Company shouldn't be created from another Company object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a Company object.
     */
    Company(Company& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a Company object.
     * 
     * @details The Company shouldn't be created from another Company object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const Company object.
     */
    void operator=(const Company& obj) = delete;

    /**
     * @fn      handlePorject
     * @brief   Handles an incoming project to work on.
     * 
     * @details The function checks if the workload is sustainable.
     * 
     * @param   requiredWork Required work load to complete the project.
     * @return  true If the project is executed and completed, false otherwise.
     */
    bool handleProject(int32_t requiredWork);

protected:
    /**
     * @fn      Company
     * @brief   Construct a new Company object.
     */
    Company();

    /**
     * @fn      ~Company
     * @brief   Destroy the Company object.
     */
    ~Company();

private:
    static Company* _pInstance; /*Pointer to the Company object.*/
    static std::mutex _mutex;   /*Mutex for thread safety.*/
    IWorkResource* _resource;   /*Pointer to an IWorkResource.*/
    ResourceFactory* _factory;  /*Pointer to a ResourceFactory.*/
};

#endif  //COMPANY_H

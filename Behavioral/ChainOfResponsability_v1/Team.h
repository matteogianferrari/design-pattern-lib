/**
 * @file        Team.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Team.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef TEAM_H
#define TEAM_H

#include "IWorkResource.h"

/**
 * @class   Team "Team.h" 
 * @brief   Class that implements a team.
 * 
 * @details This class derives from the abstract class IWorkResource.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-04
 * @version 0.1
 */
class Team:
    public IWorkResource
{
public:
    /**
     * @fn      Team
     * @brief   Construct a new Team object.
     * 
     * @param   resourceA Pointer to an IWorkResource object.
     * @param   resourceB Pointer to an IWorkResource object.
     */
    Team(IWorkResource* resourceA, IWorkResource* resourceB);

    /**
     * @fn      ~Team
     * @brief   Destroy the Team object. 
     */
    ~Team() override;

    /**
     * @fn      work
     * @brief   Gets the team work done.
     * 
     * @param   workLoad The project workload to substain.
     * @return  int32_t A unit of work load done.
     */
    int32_t work(int32_t workLoad) override;

    /**
     * @fn      getWorkCapability
     * @brief   Retreives the potential work that the team can substain.
     * 
     * @return  int32_t A unit of potential work load.
     */
    int32_t getWorkCapability(void) override;

private:
    IWorkResource* _resourceA;  /*Pointer to an IWorkResource object.*/
    IWorkResource* _resourceB;  /*Pointer to an IWorkResource object.*/
};

#endif  //TEAM_H

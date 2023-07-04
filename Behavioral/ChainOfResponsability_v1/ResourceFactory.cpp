#include "ResourceFactory.h"
#include "Employee.h"
#include "Team.h"
#include "Department.h"


ResourceFactory::ResourceFactory()
{
}


ResourceFactory::~ResourceFactory()
{
}


IWorkResource* ResourceFactory::factoryMethod(std::string resourceType)
{
    if(resourceType == "Team")
    {
        //Creates the team components
        IWorkResource* resourceA {factoryMethod("Employee")};
        IWorkResource* resourceB {factoryMethod("Employee")};

        return new Team {resourceA, resourceB};
    }
    else if(resourceType == "Department")
    {
        //Creates the department components
        IWorkResource* resourceA {factoryMethod("Team")};
        IWorkResource* resourceB {factoryMethod("Team")};
        IWorkResource* resourceC {factoryMethod("Employee")};

        return new Department {resourceA, resourceB, resourceC};
    }
    else
        return new Employee {};
}

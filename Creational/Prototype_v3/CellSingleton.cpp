#include "CellSingleton.h"


//The static member of the CellSingleton class need to be initialised outside the constructor
std::mutex CellSingleton::_mutex {};
ICell* CellSingleton::_pInstance {nullptr};


CellSingleton::CellSingleton()
{
}


CellSingleton::~CellSingleton()
{
    delete _pInstance;
}


ICell* CellSingleton::getCell(std::string& type)
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
    {
        if(type == "Plant")
        {
            std::string plantType {"Abete"};
            _pInstance = new PlantCell {plantType};
        }
        else    //default is Fungi
        {
            std::string fungiType {"Porcino"};
            _pInstance = new FungiCell {fungiType};
        }
    }

    return _pInstance;
}

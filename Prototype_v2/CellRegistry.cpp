#include "CellRegistry.h"


//The static member of the CellRegistry class need to be initialised outside the constructor
std::mutex CellRegistry::_mutex {};
CellRegistry* CellRegistry::_pInstance {nullptr};


CellRegistry::CellRegistry():
    _hashMap {}
{
}


CellRegistry::~CellRegistry()
{
}


CellRegistry* CellRegistry::getCellRegistry(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
    {
        _pInstance = new CellRegistry {};
    }
    return _pInstance;
}


void CellRegistry::addCell(std::string& key, ICell* cell)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _hashMap[key] = cell;
}


ICell* CellRegistry::getCell(std::string& key)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return _hashMap[key]->clone();
}

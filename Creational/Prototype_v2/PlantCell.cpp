#include <cstring>
#include <iostream>
#include "PlantCell.h"


PlantCell::PlantCell(std::string& plant):
    _mutex {},
    _plant {plant}
{
}
    

PlantCell::PlantCell(PlantCell& cell):
    _mutex {},  //Th mutex cannot be copied
    _plant {cell._plant}
{
}


PlantCell::~PlantCell()
{
}


ICell* PlantCell::clone(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    //Clones the fungi cell object using the copy constructor
    return new PlantCell {*this};
}


std::string& PlantCell::getType(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return _plant;
}


void PlantCell::photosyntesis(void)
{ 
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "The cell is doing the photosyntesis." << std::endl;
}


void PlantCell::print(std::ostream& os)
{
    std::lock_guard<std::mutex> lock {_mutex};
    os << "Plant cell:" << std::endl;
    os << "\t-Plant type: " << _plant << "(" << &_plant << ")" << std::endl;
}

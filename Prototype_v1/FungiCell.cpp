#include <cstring>
#include <iostream>
#include "FungiCell.h"


FungiCell::FungiCell(std::string& fungi):
    _mutex {},
    _fungi {fungi}
{
}
    

FungiCell::FungiCell(FungiCell& cell):
    _mutex {},  //Th mutex cannot be copied
    _fungi {cell._fungi}
{
}


FungiCell::~FungiCell()
{
}


ICell* FungiCell::clone(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    //Clones the fungi cell object using the copy constructor
    return new FungiCell {*this};
}


void FungiCell::absorb(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "The cell is absorbing nutrients." << std::endl;
}


void FungiCell::print(std::ostream& os)
{
    std::lock_guard<std::mutex> lock {_mutex};
    os << "Fungi cell:" << std::endl;
    os << "\t-Fungi type: " << _fungi << "(" << &_fungi << ")" << std::endl;
}

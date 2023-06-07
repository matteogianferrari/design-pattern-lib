#include <iostream>
#include <string>
#include "PlantCell.h"
#include "FungiCell.h"


void client1(ICell* pCell)
{
    ICell* copy = pCell->clone();
    std::cout << copy;

    delete copy;
}


void client2(PlantCell* pCell)
{
    std::cout << pCell;
    pCell->photosyntesis();
}


void client3(FungiCell* pCell)
{
    std::cout << pCell;
    pCell->absorb();
}


int main(int argc, char** argv)
{
    std::string plantName {"Abete"};
    std::string fungiName {"Porcino"};

    PlantCell plantCell {plantName};
    FungiCell fungiCell {fungiName};

    client1(&plantCell);
    client2(&plantCell);
    client3(&fungiCell);

    return 0;
}
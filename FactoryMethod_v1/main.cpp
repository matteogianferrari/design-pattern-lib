#include "ICnc.h"
#include "ICncFactory.h"
#include "LatheCnc.h"
#include "LatheCncFactory.h"
#include "MillCnc.h"
#include "MillCncFactory.h"
#include <iostream>
//-Implement the factory method, abstract class with no factoryMethod implementation (only virtual definition = 0).

void client(ICncFactory* pFactory)
{
    std::string partProgramName {"90351209_F1"};

    pFactory->setupCnc(partProgramName);
}


int main(int, char**) {
    LatheCncFactory latheFactory {};
    client(&latheFactory);
    MillCncFactory millFactory {};
    client(&millFactory);

    return 0;
}

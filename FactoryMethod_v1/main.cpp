#include "ICnc.h"
#include "ICncFactory.h"
#include "LatheCnc.h"
#include "LatheCncFactory.h"
#include "MillCnc.h"
#include "MillCncFactory.h"
#include <iostream>

void client(ICncFactory* pFactory)
{
    pFactory->setupCnc();
}

int main(int, char**) {
    LatheCncFactory latheFactory {};
    client(&latheFactory);
    MillCncFactory millFactory {};
    client(&millFactory);

    return 0;
}

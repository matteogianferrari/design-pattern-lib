#include <iostream>

#include "ILog.h"
#include "StdLog.h"

ILog* getLogging()
{
    static StdLog logging {};
    return &logging;
}


int main(int argc, char** argv) {
    getLogging()->print("Ciao %s\n", "Matteo");

    return 0;
}

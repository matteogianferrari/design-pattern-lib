#include "LogicNot.h"


LogicNot::LogicNot(ILogicBlock& inputA):
    _mutex {},
    _inputA {inputA}
{
}


LogicNot::~LogicNot()
{
}


bool LogicNot::getResult(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    return !(_inputA.getResult());
}

#include "LogicAnd.h"


LogicAnd::LogicAnd(ILogicBlock& inputA, ILogicBlock& inputB):
    _mutex {},
    _inputA {inputA},
    _inputB {inputB}
{
}


LogicAnd::~LogicAnd()
{
}


bool LogicAnd::getResult(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    return _inputA.getResult() && _inputB.getResult();
}

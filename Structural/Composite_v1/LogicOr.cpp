#include "LogicOr.h"


LogicOr::LogicOr(ILogicBlock& inputA, ILogicBlock& inputB):
    _mutex {},
    _inputA {inputA},
    _inputB {inputB}
{
}


LogicOr::~LogicOr()
{
}


bool LogicOr::getResult(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    return _inputA.getResult() || _inputB.getResult();
}

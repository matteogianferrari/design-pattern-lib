#include <iostream>
#include "UsbAdapterCToA.h"


UsbAdapterCToA::UsbAdapterCToA():
    _mutex {}
{
}


UsbAdapterCToA::~UsbAdapterCToA()
{
}


void UsbAdapterCToA::plugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    plug();
}


void UsbAdapterCToA::unplugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    unplug();
}


void UsbAdapterCToA::dataTransfer(std::string data)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "The data transfer velocity is limited in the adapter by the UsbTypeA." << std::endl;
    fastDataTransfer(data);
}

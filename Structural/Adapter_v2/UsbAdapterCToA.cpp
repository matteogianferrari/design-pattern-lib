#include <iostream>
#include "UsbAdapterCToA.h"


UsbAdapterCToA::UsbAdapterCToA(UsbTypeC* pUsb):
    _mutex {},
    _pUsb {pUsb}
{
}


UsbAdapterCToA::~UsbAdapterCToA()
{
}


void UsbAdapterCToA::plugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    _pUsb->plug();
}


void UsbAdapterCToA::unplugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    _pUsb->unplug();
}


void UsbAdapterCToA::dataTransfer(std::string data)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "The data transfer velocity is limited in the adapter by the UsbTypeA." << std::endl;
    _pUsb->fastDataTransfer(data);
}

#include <iostream>
#include "UsbTypeC.h"


UsbTypeC::UsbTypeC():
    _mutex {}
{
}


UsbTypeC::~UsbTypeC()
{
}


void UsbTypeC::plug(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "UsbTypeC plugged." << std::endl; 
}


void UsbTypeC::unplug(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "UsbTypeC unplugged." << std::endl; 
}


void UsbTypeC::fastDataTransfer(std::string data)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "Fast Data transferred at UsbTypeC speed: " << data << std::endl; 
}

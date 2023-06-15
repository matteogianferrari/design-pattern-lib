#include <iostream>
#include "UsbTypeA.h"


UsbTypeA::UsbTypeA():
    _mutex {}
{
}


UsbTypeA::~UsbTypeA()
{
}


void UsbTypeA::plugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "UsbTypeA plugged." << std::endl; 
}


void UsbTypeA::unplugOriented(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "UsbTypeA unplugged." << std::endl; 
}


void UsbTypeA::dataTransfer(std::string data)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "Data transferred at UsbTypeA speed: " << data << std::endl; 
}

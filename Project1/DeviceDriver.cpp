#include "DeviceDriver.h"
#include <stdexcept>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {}

int DeviceDriver::read(long address) {
    int ref = (int)(m_hardware->read(address));
    for (int i = 0; i < 4; i++) {
        int test = (int)(m_hardware->read(address));
        if (ref != test) {
            throw std::invalid_argument("Address Not equal!");
        }
    }
    return ref;
}

void DeviceDriver::write(long address, int data) {
    if (read(address) != 0xFF) {
        throw std::invalid_argument("Already written");
    }
    else {
        m_hardware->write(address, (unsigned char)data);
    }
}
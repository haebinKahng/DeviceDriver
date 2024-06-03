#include "DeviceDriver.h"
#include <stdexcept>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {}

int DeviceDriver::read(long address) {
    int ref = (int)(m_hardware->read(address));
    checkvalue(ref, address);
    return ref;
}

void DeviceDriver::checkvalue(int ref, long address) {
    for (int i = 0; i < 4; i++) {
        int test = (int)(m_hardware->read(address));
        if (ref != test) {
            throw std::exception("Address Not equal!");
        }
    }
}

void DeviceDriver::write(long address, int data) {
    checkpage(address);
    m_hardware->write(address, (unsigned char)data);
}

void DeviceDriver::checkpage(long address) {
    int result = (int)(m_hardware->read(address));
    if (result != 0xFF) {
        throw std::exception("Already written");
    }
}